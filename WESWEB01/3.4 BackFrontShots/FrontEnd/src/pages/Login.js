import React, { useState } from 'react';
import { TextField, Button, Container, Typography } from '@mui/material';
import API from '../api';
import { useNavigate } from 'react-router-dom';

const Login = () => {
  const navigate = useNavigate();
  const [form, setForm] = useState({ email: '', password: '' });

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleLogin = async (e) => {
    e.preventDefault();
    try {
      const response = await API.post('/login', form);
      if (response.status === 200) {
        const { access_token, user_id } = response.data;
        localStorage.setItem('token', access_token);
        localStorage.setItem('userId', user_id);

        // Optionally fetch user info or decode token to get userId
        // For now, let's fetch user info from the email if we want:
        // The server doesn't have a "get user by email" route in your example,
        // so we might do a separate request or store user ID after we get it from /user if you had that endpoint. 
        // We'll store user ID as well if you prefer:
        // (But let's skip that for now if we only need the token.)

        navigate('/');
      }
    } catch (error) {
      console.error(error);
      alert(error.response?.data?.error || 'Login failed');
    }
  };

  return (
    <Container maxWidth="sm" sx={{ mt: 4 }}>
      <Typography variant="h5" gutterBottom>
        Login
      </Typography>
      <form onSubmit={handleLogin}>
        <TextField
          label="Email"
          name="email"
          value={form.email}
          onChange={handleChange}
          fullWidth
          margin="normal"
          required
        />
        <TextField
          label="Password"
          name="password"
          value={form.password}
          onChange={handleChange}
          type="password"
          fullWidth
          margin="normal"
          required
        />
        <Button variant="contained" type="submit" sx={{ mt: 2 }}>
          Login
        </Button>
      </form>
    </Container>
  );
};

export default Login;
