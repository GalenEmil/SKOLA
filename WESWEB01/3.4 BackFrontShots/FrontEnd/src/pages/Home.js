import React, { useEffect, useState } from 'react';
import API from '../api';
import { Container, Typography } from '@mui/material';
import Post from '../components/Post';

const Home = () => {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    const fetchLatestPosts = async () => {
      try {
        const response = await API.get('/posts?count=10');
        setPosts(response.data);
      } catch (error) {
        console.error(error);
      }
    };
    fetchLatestPosts();
  }, []);

  return (
    <Container maxWidth="md" sx={{ mt: 2 }}>
      <Typography variant="h4" gutterBottom>
        Latest Posts
      </Typography>
      {posts.map((post) => (
        <Post post={post} />
      ))}
    </Container>
  );
};

export default Home;
