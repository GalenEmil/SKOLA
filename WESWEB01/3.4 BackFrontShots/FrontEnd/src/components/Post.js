
import React from 'react';
import { Typography, Card, CardContent } from '@mui/material';

const Post = ({ post }) => {
  return (
    <Card key={post.id} sx={{ mb: 2 }}>
      <CardContent>
        <Typography variant="h6">{post.title}</Typography>
        <Typography variant="body2" color="text.secondary">
          {post.text}
        </Typography>
        <Typography variant="caption" display="block">
          By {post.name}
        </Typography>
        <Typography variant="caption" display="block">
          {new Date(post.date).toLocaleString()}
        </Typography>
      </CardContent>
    </Card>
  );
};

export default Post;