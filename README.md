# Remote Audio Project - REST API with JSON

A simple but functional remote audio control system using REST API and JSON for communication.

## Overview

This project provides a REST API server for controlling audio playback remotely. The server exposes JSON-based endpoints that allow you to:
- Control audio playback (play, pause, stop)
- Adjust volume
- Manage playlists
- Monitor player status

## Architecture

The project consists of two main components:

1. **Audio Server** (`audio_server.py`): Flask-based REST API server
2. **Audio Client** (`audio_client.py`): Command-line client demonstrating API usage

All communication uses JSON format for request/response data.

## Installation

### Prerequisites
- Python 3.7 or higher
- pip (Python package manager)

### Setup

1. Install dependencies:
```bash
pip install -r requirements.txt
```

## Usage

### Starting the Server

Run the audio server:
```bash
python audio_server.py
```

The server will start on `http://localhost:5000` by default.

### Using the Client

In a separate terminal, use the client to control audio:

```bash
# Check server health
python audio_client.py health

# Get current status
python audio_client.py status

# Play an audio file
python audio_client.py play song.mp3

# Pause playback
python audio_client.py pause

# Stop playback
python audio_client.py stop

# Set volume (0-100)
python audio_client.py volume 75

# Add file to playlist
python audio_client.py add song1.mp3
python audio_client.py add song2.mp3

# View playlist
python audio_client.py playlist

# Clear playlist
python audio_client.py clear
```

## API Documentation

### Base URL
```
http://localhost:5000
```

### Endpoints

#### 1. Health Check
```
GET /api/health
```

**Response:**
```json
{
  "success": true,
  "message": "Remote Audio Server is running",
  "version": "1.0.0"
}
```

#### 2. Get Status
```
GET /api/status
```

**Response:**
```json
{
  "success": true,
  "data": {
    "status": "playing",
    "current_file": "song.mp3",
    "volume": 50,
    "position": 0,
    "playlist": ["song1.mp3", "song2.mp3"]
  }
}
```

#### 3. Play Audio
```
POST /api/play
Content-Type: application/json

{
  "file": "song.mp3"
}
```

**Response:**
```json
{
  "success": true,
  "message": "Playing song.mp3",
  "data": { ... }
}
```

#### 4. Pause Audio
```
POST /api/pause
```

**Response:**
```json
{
  "success": true,
  "message": "Audio paused",
  "data": { ... }
}
```

#### 5. Stop Audio
```
POST /api/stop
```

**Response:**
```json
{
  "success": true,
  "message": "Audio stopped",
  "data": { ... }
}
```

#### 6. Set Volume
```
POST /api/volume
Content-Type: application/json

{
  "volume": 75
}
```

**Response:**
```json
{
  "success": true,
  "message": "Volume set to 75",
  "data": { ... }
}
```

#### 7. Get Playlist
```
GET /api/playlist
```

**Response:**
```json
{
  "success": true,
  "data": {
    "playlist": ["song1.mp3", "song2.mp3"]
  }
}
```

#### 8. Add to Playlist
```
POST /api/playlist
Content-Type: application/json

{
  "file": "song.mp3"
}
```

**Response:**
```json
{
  "success": true,
  "message": "Added song.mp3 to playlist",
  "data": {
    "playlist": ["song1.mp3", "song2.mp3", "song.mp3"]
  }
}
```

#### 9. Clear Playlist
```
DELETE /api/playlist
```

**Response:**
```json
{
  "success": true,
  "message": "Playlist cleared",
  "data": {
    "playlist": []
  }
}
```

## Testing with curl

You can also test the API using curl:

```bash
# Health check
curl http://localhost:5000/api/health

# Get status
curl http://localhost:5000/api/status

# Play audio
curl -X POST http://localhost:5000/api/play \
  -H "Content-Type: application/json" \
  -d '{"file": "song.mp3"}'

# Set volume
curl -X POST http://localhost:5000/api/volume \
  -H "Content-Type: application/json" \
  -d '{"volume": 75}'

# Add to playlist
curl -X POST http://localhost:5000/api/playlist \
  -H "Content-Type: application/json" \
  -d '{"file": "newsong.mp3"}'
```

## Features

- **RESTful API**: Standard HTTP methods (GET, POST, DELETE)
- **JSON Communication**: All requests and responses use JSON format
- **Thread-safe**: State management with thread locking
- **Simple Client**: Command-line client for easy interaction
- **Error Handling**: Proper error responses with status codes
- **Health Monitoring**: Health check endpoint for monitoring

## Project Structure

```
.
├── audio_server.py      # Flask REST API server
├── audio_client.py      # Command-line client
├── requirements.txt     # Python dependencies
└── README.md           # This file
```

## Future Enhancements

Potential improvements for the project:
- Actual audio playback integration (e.g., using pygame, pydub)
- File upload/download capabilities
- Authentication and authorization
- WebSocket support for real-time updates
- Web-based UI client
- Audio streaming capabilities
- Support for multiple audio formats
- Queue management for playlist

## License

This is a sandbox project for demonstration purposes.

## Notes

This is a demonstration project that simulates audio control. It maintains state but doesn't actually play audio files. To add real audio playback, you would need to integrate an audio library like pygame or pydub.
