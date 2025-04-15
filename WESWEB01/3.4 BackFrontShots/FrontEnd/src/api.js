
import axios from 'axios';

const API = axios.create({
  baseURL: 'http://localhost:9000', // Your Flask backend
});

// Attach token for authorized requests
API.interceptors.request.use((config) => {
  const token = localStorage.getItem('token');
  if (token) {
    config.headers.Authorization = `Bearer ${token}`;
  }
  return config;
});

export default API;