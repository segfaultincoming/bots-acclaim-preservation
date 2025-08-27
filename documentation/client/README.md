# BOTS Game Reverse Engineering Documentation

This directory contains comprehensive documentation for the BOTS game, a 3D mech action game developed by NLOG Soft around 2006-2008.

## Documentation Files

### [Game Analysis](BOTS_Game_Analysis.md)

Complete overview of the game structure, mechanics, and technical architecture including:

- Game overview and timeline
- Directory structure breakdown
- Asset organization analysis
- Character types and game modes
- Network architecture details

### [Script Files](Script_Files_Documentation.md)

Detailed analysis of the game's configuration system including:

- UI layout definitions (.sct files)
- Binary data files (.bin files)
- System configuration files (.sys files)
- Coordinate systems and formatting
- Localization and text handling

### [File Formats](File_Formats_Reference.md)

Technical reference for all file formats found in the game:

- Model and animation formats (.ba0, .ba2, .bon, .bsc)
- Map and environment formats (.map, .obj, .val, .flu)
- Effect and particle formats (.eff)
- UI and image formats (.sct, .tga, .dds)
- Audio and executable formats

## Key Findings Summary

### Game Architecture

- **Engine**: Custom DirectX 9.0+ based 3D engine
- **Anti-Cheat**: GameGuard protection system with Yoda's Cryptor 1.x packing
- **Network**: Client-server multiplayer architecture
- **Platform**: Windows (Win32)

### Content Scale

- **Maps**: 44 different maps across multiple game modes
- **Models**: 4000+ model files for characters, weapons, objects
- **Effects**: 233+ particle effect configurations
- **Audio**: 330 sound files for combat, movement, and ambiance
- **UI Elements**: Comprehensive interface system with pixel-perfect positioning

### Game Modes

1. **Battle Mode** - PvP mech combat
2. **Sector Mode** - PvE exploration
3. **Base Mode** - Base defense/capture gameplay

### Character System

- **3 Robot Types**: Patch, Surge, Ram
- **Transformation Mechanics**: Multiple forms per character
- **Team System**: Red vs Blue team variants
- **Equipment System**: Modular parts and upgrades

### Technical Features

- Advanced particle effects system
- Complex map chunking for large environments
- Comprehensive UI scripting system
- Detailed audio engine with positional sound
- Anti-cheat integration at multiple levels

## Development Timeline

- **2006/01/26** - Initial development start
- **2006-2008** - Active development with 66 documented patches
- **2008/04/29** - Last recorded update (Patch 066)

## File Organization

The game uses a sophisticated file organization system:

- Binary archives (.dat) for main content
- Chunked map files for performance
- Modular character system with separate components
- Efficient texture and audio management
- **bots-dat.exe**: Originally, that was named **bots.data** and was executed using **bots.bat**

## Game Client Access

The original game clients are now hosted in a dedicated repository:

- **Repository**: [bots-acclaim-clients](https://github.com/segfaultincoming/bots-acclaim-clients)
- **Purpose**: Centralized archive of BOTS!! game client versions
- **Content**: Protected executables and game assets for analysis

## Reverse Engineering Notes

This analysis was conducted through:

- Static file analysis of 5000+ game assets
- Script parsing and configuration review
- Directory structure examination
- Cross-referencing of file dependencies
- Timeline reconstruction from patch logs
- Protection system analysis (Yoda's Cryptor 1.x defeat)
- GameGuard architecture mapping and component identification

## Usage

These documents serve as a comprehensive reference for:

- Game preservation efforts
- Technical research and education
- Multiplayer game networking analysis

---

_Analysis completed: 2025-08-22_  
_Total files analyzed: 5000+_  
_Documentation pages: 5_
