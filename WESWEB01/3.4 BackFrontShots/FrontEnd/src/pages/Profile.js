import React, { useEffect, useState } from 'react';
import API from '../api';
import { Container, Typography, Card, CardContent, Button } from '@mui/material';

const Profile = () => {
  const storedUserId = localStorage.getItem('userId');
  const [user, setUser] = useState(null);
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    if (!storedUserId) {
      // Possibly redirect to login or handle the error
      return;
    }

    const fetchProfileAndPosts = async () => {
      try {
        // 1) Fetch user profile
        const userResp = await API.get(`/user/${storedUserId}`);
        setUser(userResp.data);

        // 2) Fetch user posts
        const postsResp = await API.get(`/user/${storedUserId}/posts`);
        setPosts(postsResp.data);
      } catch (error) {
        console.error(error);
      }
    };

    fetchProfileAndPosts();
  }, [storedUserId]);

  const handleDelete = async (postId) => {
    try {
      await API.delete(`/posts/${postId}`);
      setPosts(posts.filter((p) => p.id !== postId));
    } catch (error) {
      console.error(error);
      alert(error.response?.data?.error || 'Failed to delete post');
    }
  };

  if (!storedUserId) {
    return (
      <Container sx={{ mt: 4 }}>
        <Typography variant="h6">You are not logged in.</Typography>
      </Container>
    );
  }

  return (
    <Container maxWidth="md" sx={{ mt: 2 }}>
      <Typography variant="h4" gutterBottom>
        Profile
      </Typography>
      {user && (
        <>
          <Typography variant="h6">Name: {user.name}</Typography>
          <Typography variant="body1">Email: {user.email}</Typography>
        </>
      )}
      <Typography variant="h5" sx={{ mt: 4 }}>
        My Posts
      </Typography>
      {posts.map((post) => (
        <Card key={post.id} sx={{ mb: 2 }}>
          <CardContent>
            <Typography variant="h6">{post.title}</Typography>
            <Typography variant="body2" color="text.secondary">
              {post.text}
            </Typography>
            <Typography variant="caption" display="block">
              Posted on {new Date(post.date).toLocaleString()}
            </Typography>
            <Button
              variant="contained"
              color="error"
              sx={{ mt: 1 }}
              onClick={() => handleDelete(post.id)}
            >
              Delete
            </Button>
          </CardContent>
        </Card>
      ))}
    </Container>
  );
};

export default Profile;
