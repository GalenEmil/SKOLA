import React, { useState } from 'react';
import { TextField, Button, Container, Typography } from '@mui/material';
import API from '../api';
import { useNavigate } from 'react-router-dom';

const Register = () => {
  const navigate = useNavigate();
  const [form, setForm] = useState({ email: '', name: '', password: '' });

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleRegister = async (e) => {
    e.preventDefault();
    try {
      const response = await API.post('/register', form);
      if (response.status === 201) {
        // Registration successful
        alert('Registered successfully! You can now login.');
        navigate('/login');
      }
    } catch (error) {
      console.error(error);
      alert(error.response?.data?.error || 'Registration failed');
    }
  };

  return (
    <Container maxWidth="sm" sx={{ mt: 4 }}>
      <Typography variant="h5" gutterBottom>
        Register
      </Typography>
      <form onSubmit={handleRegister}>
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
          label="Name"
          name="name"
          value={form.name}
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
          Register
        </Button>
      </form>
    </Container>
  );
};

export default Register;
