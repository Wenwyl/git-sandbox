#!/usr/bin/env python3
"""
Remote Audio Server - REST API for controlling audio playback remotely
Uses Flask for REST API and JSON for data exchange
"""

from flask import Flask, jsonify, request
import os
from threading import Lock

app = Flask(__name__)

# Audio player state
audio_state = {
    'status': 'stopped',  # stopped, playing, paused
    'current_file': None,
    'volume': 50,
    'position': 0,
    'playlist': []
}

# Thread lock for state management
state_lock = Lock()

@app.route('/api/status', methods=['GET'])
def get_status():
    """Get current audio player status"""
    with state_lock:
        return jsonify({
            'success': True,
            'data': audio_state
        })

@app.route('/api/play', methods=['POST'])
def play_audio():
    """Start or resume audio playback"""
    data = request.get_json() or {}
    filename = data.get('file')
    
    with state_lock:
        if filename:
            audio_state['current_file'] = filename
            audio_state['position'] = 0
        
        if audio_state['current_file'] is None:
            return jsonify({
                'success': False,
                'error': 'No audio file specified'
            }), 400
        
        audio_state['status'] = 'playing'
        
        return jsonify({
            'success': True,
            'message': f"Playing {audio_state['current_file']}",
            'data': audio_state
        })

@app.route('/api/pause', methods=['POST'])
def pause_audio():
    """Pause audio playback"""
    with state_lock:
        if audio_state['status'] == 'playing':
            audio_state['status'] = 'paused'
            return jsonify({
                'success': True,
                'message': 'Audio paused',
                'data': audio_state
            })
        else:
            return jsonify({
                'success': False,
                'error': 'Audio is not playing'
            }), 400

@app.route('/api/stop', methods=['POST'])
def stop_audio():
    """Stop audio playback"""
    with state_lock:
        audio_state['status'] = 'stopped'
        audio_state['position'] = 0
        
        return jsonify({
            'success': True,
            'message': 'Audio stopped',
            'data': audio_state
        })

@app.route('/api/volume', methods=['POST'])
def set_volume():
    """Set audio volume (0-100)"""
    data = request.get_json() or {}
    volume = data.get('volume')
    
    if volume is None:
        return jsonify({
            'success': False,
            'error': 'Volume parameter required'
        }), 400
    
    try:
        volume = int(volume)
        if volume < 0 or volume > 100:
            raise ValueError('Volume must be between 0 and 100')
    except (ValueError, TypeError) as e:
        return jsonify({
            'success': False,
            'error': str(e)
        }), 400
    
    with state_lock:
        audio_state['volume'] = volume
        
        return jsonify({
            'success': True,
            'message': f'Volume set to {volume}',
            'data': audio_state
        })

@app.route('/api/playlist', methods=['GET'])
def get_playlist():
    """Get current playlist"""
    with state_lock:
        return jsonify({
            'success': True,
            'data': {
                'playlist': audio_state['playlist']
            }
        })

@app.route('/api/playlist', methods=['POST'])
def add_to_playlist():
    """Add file to playlist"""
    data = request.get_json() or {}
    filename = data.get('file')
    
    if not filename:
        return jsonify({
            'success': False,
            'error': 'File parameter required'
        }), 400
    
    with state_lock:
        if filename not in audio_state['playlist']:
            audio_state['playlist'].append(filename)
        
        return jsonify({
            'success': True,
            'message': f'Added {filename} to playlist',
            'data': {
                'playlist': audio_state['playlist']
            }
        })

@app.route('/api/playlist', methods=['DELETE'])
def clear_playlist():
    """Clear the playlist"""
    with state_lock:
        audio_state['playlist'] = []
        
        return jsonify({
            'success': True,
            'message': 'Playlist cleared',
            'data': {
                'playlist': audio_state['playlist']
            }
        })

@app.route('/api/health', methods=['GET'])
def health_check():
    """Health check endpoint"""
    return jsonify({
        'success': True,
        'message': 'Remote Audio Server is running',
        'version': '1.0.0'
    })

if __name__ == '__main__':
    print("Starting Remote Audio Server...")
    print("REST API available at http://localhost:5000")
    print("Press Ctrl+C to stop")
    app.run(host='0.0.0.0', port=5000, debug=False)
