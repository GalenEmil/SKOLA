import React, { useState } from 'react';
import API from '../api';
import { Container, TextField, Button, Typography } from '@mui/material';
import { useNavigate } from 'react-router-dom';

const CreatePost = () => {
  const navigate = useNavigate();
  const [form, setForm] = useState({ title: '', text: '' });

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleCreate = async (e) => {
    e.preventDefault();
    try {
      await API.post('/posts', form, {
        headers: {
          'Content-Type': 'application/json'
        }
      });
      alert('Post created!');
      navigate('/');
    } catch (error) {
      console.error(error);
      alert(error.response?.data?.error || 'Failed to create post');
    }
  };

  return (
    <Container maxWidth="sm" sx={{ mt: 4 }}>
      <Typography variant="h5" gutterBottom>
        Create a Post
      </Typography>
      <form onSubmit={handleCreate}>
        <TextField
          label="Title"
          name="title"
          value={form.title}
          onChange={handleChange}
          fullWidth
          margin="normal"
          required
        />
        <TextField
          label="Text"
          name="text"
          value={form.text}
          onChange={handleChange}
          fullWidth
          multiline
          rows={4}
          margin="normal"
          required
        />
        <Button variant="contained" type="submit" sx={{ mt: 2 }}>
          Create
        </Button>
      </form>
    </Container>
  );
};

export default CreatePost;
