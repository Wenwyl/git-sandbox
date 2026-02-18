#!/usr/bin/env python3
"""
Remote Audio Client - Simple client to interact with the Remote Audio Server
Demonstrates usage of the REST API with JSON
"""

import requests
import json
import sys

class AudioClient:
    def __init__(self, base_url='http://localhost:5000'):
        self.base_url = base_url
    
    def _make_request(self, method, endpoint, data=None):
        """Make HTTP request to the server"""
        url = f"{self.base_url}{endpoint}"
        try:
            if method == 'GET':
                response = requests.get(url)
            elif method == 'POST':
                response = requests.post(url, json=data)
            elif method == 'DELETE':
                response = requests.delete(url)
            else:
                raise ValueError(f"Unsupported HTTP method: {method}")
            
            return response.json()
        except requests.exceptions.ConnectionError:
            return {
                'success': False,
                'error': 'Cannot connect to server. Is it running?'
            }
        except Exception as e:
            return {
                'success': False,
                'error': str(e)
            }
    
    def get_status(self):
        """Get current player status"""
        return self._make_request('GET', '/api/status')
    
    def play(self, filename=None):
        """Play audio file"""
        data = {'file': filename} if filename else None
        return self._make_request('POST', '/api/play', data)
    
    def pause(self):
        """Pause audio playback"""
        return self._make_request('POST', '/api/pause')
    
    def stop(self):
        """Stop audio playback"""
        return self._make_request('POST', '/api/stop')
    
    def set_volume(self, volume):
        """Set volume (0-100)"""
        return self._make_request('POST', '/api/volume', {'volume': volume})
    
    def get_playlist(self):
        """Get current playlist"""
        return self._make_request('GET', '/api/playlist')
    
    def add_to_playlist(self, filename):
        """Add file to playlist"""
        return self._make_request('POST', '/api/playlist', {'file': filename})
    
    def clear_playlist(self):
        """Clear playlist"""
        return self._make_request('DELETE', '/api/playlist')
    
    def health_check(self):
        """Check if server is healthy"""
        return self._make_request('GET', '/api/health')

def print_response(response):
    """Pretty print JSON response"""
    print(json.dumps(response, indent=2))

def main():
    if len(sys.argv) < 2:
        print("Usage: audio_client.py <command> [args]")
        print("\nCommands:")
        print("  status              - Get player status")
        print("  play <file>         - Play audio file")
        print("  pause               - Pause playback")
        print("  stop                - Stop playback")
        print("  volume <0-100>      - Set volume")
        print("  playlist            - Show playlist")
        print("  add <file>          - Add file to playlist")
        print("  clear               - Clear playlist")
        print("  health              - Check server health")
        sys.exit(1)
    
    client = AudioClient()
    command = sys.argv[1].lower()
    
    if command == 'status':
        response = client.get_status()
    elif command == 'play':
        filename = sys.argv[2] if len(sys.argv) > 2 else None
        response = client.play(filename)
    elif command == 'pause':
        response = client.pause()
    elif command == 'stop':
        response = client.stop()
    elif command == 'volume':
        if len(sys.argv) < 3:
            print("Error: Volume value required")
            sys.exit(1)
        response = client.set_volume(sys.argv[2])
    elif command == 'playlist':
        response = client.get_playlist()
    elif command == 'add':
        if len(sys.argv) < 3:
            print("Error: Filename required")
            sys.exit(1)
        response = client.add_to_playlist(sys.argv[2])
    elif command == 'clear':
        response = client.clear_playlist()
    elif command == 'health':
        response = client.health_check()
    else:
        print(f"Unknown command: {command}")
        sys.exit(1)
    
    print_response(response)

if __name__ == '__main__':
    main()
