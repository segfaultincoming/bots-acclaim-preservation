# BOTS!! (BOUT!!) Preservation Project

A comprehensive reverse engineering and preservation effort for **BOTS!! (BOUT!!)**, a 3D mech action game developed by NLOG Soft between 2006-2008. This project aims to document, analyze, and preserve this Korean multiplayer mech combat game for future generations.

## 🎮 Game Overview

**BOTS!!** is a 3D multiplayer mech combat game featuring:

- **3 Robot Types**: Patch, Surge, and Ram with transformation mechanics
- **3 Game Modes**: Battle (PvP), Sector (PvE), and Base (defense/capture)
- **Advanced Engine**: Custom DirectX 9.0+ based 3D engine with particle effects
- **Multiplayer Focus**: Client-server architecture supporting team-based combat
- **Korean Origin**: Developed by NLOG Soft with 66 documented patches

## 🔍 Analysis Scope

### Content Analysis

- **5,000+ Game Assets**: Models, textures, audio, maps, and scripts
- **44 Maps**: Across multiple game modes and environments
- **4,000+ Models**: Characters, weapons, objects, and equipment
- **233+ Effects**: Particle systems and visual effects
- **330 Audio Files**: Combat sounds, movement, and ambiance

### Technical Analysis

- **File Format Reverse Engineering**: Custom binary formats (.ba0, .ba2, .bon, .bsc)
- **Script System Analysis**: UI layouts, configuration files, and localization
- **Network Architecture**: Multiplayer client-server communication and P2P protocols
- **Protection System**: GameGuard anti-cheat with Yoda's Cryptor 1.x packing
- **Protocol Analysis**: TCP packet structures and game state synchronization

## 🛡️ Protection System Analysis

The game uses sophisticated anti-tampering protection:

- **Yoda's Cryptor 1.x**: Multi-layer encryption and custom compression
- **GameGuard Integration**: Distributed external file-based protection system
- **Anti-Debugging**: Runtime code decryption and debugger detection
- **Custom Compression**: Proprietary algorithms with up to 54x expansion ratios

**Current Status**: Encryption layers defeated, architecture mapped, but execution challenges remain.

## 📚 Documentation

### [Client Documentation](documentation/client/README.md)

Complete reverse engineering analysis of the game client, including game mechanics, file formats, scripts, protection systems, and network protocols.

### [Game Client Repository](https://github.com/segfaultincoming/bots-acclaim-clients)

The BOTS!! game clients have been moved to a dedicated GitHub repository for better organization and accessibility. This repository contains the original game client archives from 2008, including the protected executables and game assets for analysis.

### Key Findings

- **Engine**: Custom DirectX 9.0+ 3D engine with advanced features
- **Architecture**: Modular design with efficient asset management
- **Networking**: Sophisticated client-server multiplayer system
- **Localization**: Korean language support with internationalization

## 🎯 Project Goals

1. **Preservation**: Document and preserve the game's technical architecture
2. **Open Source Server**: Create a fully functional, open-source multiplayer server
3. **Network Reverse Engineering**: Understand and replicate the P2P/TCP communication protocol
4. **Research**: Understand 2000s-era Korean game development techniques
5. **Education**: Provide insights into anti-cheat and protection systems
6. **Accessibility**: Make game mechanics and systems understandable
7. **Community Revival**: Enable multiplayer gameplay for preservation and research

## 🎯 Current Development Goals

1. **Complete Client Unpacking**: Fully extract and reconstruct the `bots.dat` executable
2. **Bypass GameGuard Protection**: Remove or disable the anti-cheat initialization sequence
3. **Achieve Game Launch**: Successfully display the login screen

## 🚧 Current Status

- ✅ **Asset Analysis**: Complete documentation of 5,000+ game files
- ✅ **File Formats**: Reverse engineered custom binary formats
- ✅ **Script System**: Analyzed UI and configuration systems
- ✅ **Protection Analysis**: Defeated encryption layers, mapped GameGuard
- 🔄 **Execution**: Working on resolving remaining launch issues
- ❌ **Game Launch**: Not yet functional due to protection system complexity

## 🛠️ Technical Challenges

### Completed

- Multi-layer encryption defeat (Yoda's Cryptor 1.x)
- Custom compression algorithm reverse engineering
- GameGuard distributed architecture mapping
- Anti-debugging technique analysis
- Basic network architecture understanding

### Remaining

- Import Address Table (IAT) reconstruction
- External dependency resolution
- Proper initialization sequence identification
- Windows PE loader compatibility

## 🌐 Server Development Goal

### Primary Objective

**Create a fully functional, open-source multiplayer server** that anyone can run to host BOTS!! games.

### Network Analysis Requirements

- **Protocol Reverse Engineering**: Understand TCP packet structures and communication flow
- **Game State Synchronization**: Map how game state is shared between clients
- **Matchmaking System**: Analyze lobby and room creation mechanisms
- **Anti-Cheat Bypass**: Understand and replicate server-side validation
- **Client-Server Handshake**: Document authentication and connection establishment

### Server Architecture Goals

- **Language**: Modern, maintainable language (C++, Rust, Go, or Python)
- **Cross-Platform**: Windows, Linux, and macOS support
- **Scalability**: Handle multiple concurrent game rooms
- **Configuration**: Easy setup and customization
- **Documentation**: Complete API and deployment guides

### Current Network Analysis Status

- 🔍 **Initial Investigation**: Basic client-server communication identified
- 📡 **Protocol Mapping**: TCP packet structures under analysis
- 🎮 **Game Logic**: Understanding game state and synchronization
- 🚧 **Server Development**: Planning phase - not yet started

## 📅 Development Timeline

- **2006/01/26**: Game development begins
- **2006-2008**: Active development with 66 patches
- **2008/04/29**: Last official update (Patch 066)
- **2025**: Reverse engineering project begins

## 🤝 Contributing

This is a preservation and research project. Contributions are welcome in:

- **Technical Analysis**: Further reverse engineering efforts
- **Documentation**: Improving and expanding analysis
- **Research**: Investigating specific game systems
- **Testing**: Validating analysis findings
- **Network Analysis**: Protocol reverse engineering and packet analysis
- **Server Development**: Building the open-source multiplayer server
- **Game Mechanics**: Understanding and documenting gameplay systems

## 📖 References

- **Developer**: NLOG Soft (Korean game studio)
- **Engine**: Custom DirectX 9.0+ 3D engine
- **Protection**: GameGuard + Yoda's Cryptor 1.x
- **Platform**: Windows (Win32)
- **Genre**: 3D Mecha Combat / Action
- **Game Clients**: [bots-acclaim-clients](https://github.com/segfaultincoming/bots-acclaim-clients) repository

## 📄 License

This project is for educational and preservation purposes. The original game and its assets remain the property of NLOG Soft. This documentation represents independent research and analysis.

---

**Project Status**: Documentation Complete, Server Development Planning  
**Last Updated**: 2025  
**Total Files Analyzed**: 5,000+  
**Documentation Pages**: 5

_Preserving the legacy of BOTS!! (BOUT!!) for future generations_
