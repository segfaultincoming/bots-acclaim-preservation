# Game Client Analysis Report - Zylon Gaming BOTS Client

## 🔄 UNPACKED - ANALYSIS IN PROGRESS

**This document covers the ongoing analysis** of the **Zylon Gaming BOTS client** that was successfully unpacked from Protector: ENIGMA protection.

**For the failed decryption attempt of the original BOTS!! client, see:**

- `Yodas_Cryptor_Summary.md` - Failed decryption of original client

---

## Protector: ENIGMA Unpacked Client

### Overview

This document provides a comprehensive analysis of the decompiled game client that was originally packed with **Protector: ENIGMA (3.140 build 2015.5.17 1:10:59)**. The client has been successfully unpacked and imported into Ghidra, revealing over 1,000,000 lines of decompiled C code.

### File Information

- **Original packed file**: `bout-zylon.dat` (13MB)
- **Decompiled C code**: `bout-zylon.dat.c` (30MB)
- **Protection**: Protector: ENIGMA v3.140
- **Build date**: 2015.5.17 1:10:59

### Entry Point Analysis

#### Primary Entry Point

The client is identified as a **Dynamic Link Library (DLL)** rather than a standalone executable, as evidenced by:

- **DllMainCRTStartup**: Located at line 901780
- **DllMain function**: Standard Windows DLL entry point
- **Function signature**: `int __fastcall ___DllMainCRTStartup(undefined4 param_1, int param_2, undefined4 param_3)`

#### Secondary Entry Points

- **GameGuard initialization**: Anti-cheat system startup
- **KidSock networking**: Socket library initialization
- **NLOGCMD startup**: Logging system initialization

### Program Structure & Sectors

#### 1. Core Game Classes

The decompiled code reveals a well-structured object-oriented architecture:

##### Battle System (`CBattlePlay`)

- **Game management**: `CommandGameEndResult()`, `ReplyGameResult()`
- **Match handling**: `RequestMatchGameUser()`, `ReplyMatchGameUserData()`
- **Loading system**: `RequestGameLoadingEnd()`, `ReplyGameLoadingEnd()`
- **Hosting**: `CommandGameHostChange()`
- **Network status**: `RequestGameNetSysStat()`, `ReplyGameNetSysStat()`

##### Lobby System (`CLobby`)

- **Game creation**: `CreateGameInit()`
- **Game joining**: `RequestJoinGame()`, `ReplyGameJoinNew()`
- **Game listing**: `RequestGameList()`, `ReplyGameList()`
- **Friend management**: `RequestFriendAdd()`, `ReplyFriendAdd()`, `RequestFriendDelete()`
- **User information**: `RequestUserInfo()`, `ReplyUserInfo()`
- **Server communication**: `RequestServerExit()`, `ReplyServerExit()`

##### Inventory System (`CInventory`)

- **Equipment management**: `RequestWearParts()`, `RequestRemoveParts()`
- **Accessory handling**: `RequestRemoveAcce()`, `ReplyAcceEquipment()`
- **Skill packs**: `RequestRemoveSkillPack()`, `ReplySkillPackEquipment()`
- **Class system**: `RequestClassChange()`, `ReplyClassChange()`
- **Item combining**: `RequestMixEnter()`, `ReplyCombine()`
- **Storage**: `InitStash()`, `DestroyStash()`

#### 2. Anti-Cheat & Security

- **GameGuard integration**: nProtect GameGuard anti-cheat system
- **Detection mechanisms**: Speed hack detection, game hack detection
- **Error handling**: GameGuard initialization error handling
- **File paths**: `C:\Zylon_Gaming\Bots\GameGuard\`

#### 3. Networking Layer

- **KidSock library**: Custom networking implementation
- **Socket management**: `CreateClientSocket()`, `ConnectToServer()`, `CloseSocket()`
- **Server connections**: Multiple socket instances for different purposes
- **Connection handling**: Timeout management (5000ms default)
- **Server addresses**: Hardcoded IP addresses (e.g., 23.111.139.188:11000)

#### 4. UI & Scripting System

- **Script files**: `.sct` files for UI components
- **UI components**: ListBox, DropDownList, PutItem interface
- **Texture files**: `.tga` files for UI elements
- **Event handling**: Event URL system

#### 5. Graphics & Rendering

- **Direct3D integration**: `g_pDirect3D` references
- **Model system**: `.bsc` and `.bon` files for 3D models
- **Character parts**: Head, body, arm, and transformation models
- **Bone system**: Complex skeletal animation system (Bone10, Bone11, Bone30, etc.)

#### 6. Audio System

- **Sound effects**: `.wav` files for game audio
- **Background music**: Win/lose music tracks
- **Audio management**: FX Sound system

#### 7. Game Mechanics

- **Character system**: Race-based character creation (3 races identified)
- **Level system**: Level display and progression
- **Transformation system**: Trans pack mechanics
- **Macro system**: F5-F8 macro keys
- **Control system**: Movement keys, attack, defend, jump, transform

#### 8. File Management

- **Data paths**: `data/models/`, `data/ui/`, `script/`
- **Registry integration**: `SOFTWARE\N-Log_Soft\Bots`
- **Installation**: `pcinstall` and setup management

### Key Observations

1. **Architecture**: Well-structured C++ code with clear class hierarchies
2. **Networking**: Custom socket library with multiple connection types
3. **Anti-cheat**: Integrated GameGuard system for security
4. **Modularity**: Separate systems for different game aspects
5. **File organization**: Clear separation of models, UI, scripts, and audio
6. **Memory management**: Proper cleanup and memory handling patterns

### Potential Analysis Areas

1. **Network protocol**: Analyze KidSock communication patterns
2. **Game logic**: Examine battle mechanics and character progression
3. **Security**: Study anti-cheat mechanisms and bypass possibilities
4. **UI system**: Understand script-based interface system
5. **File formats**: Investigate custom file formats (.bsc, .bon, .sct)

### Next Steps

1. **Function mapping**: Create a comprehensive function call graph
2. **Network analysis**: Capture and analyze network traffic
3. **Memory analysis**: Identify key data structures in memory
4. **Hook development**: Create hooks for key game functions
5. **Protocol reverse engineering**: Understand client-server communication

This analysis provides a solid foundation for further reverse engineering efforts and understanding the game's internal architecture.

---

**Status: 🔄 ANALYSIS IN PROGRESS**  
_Zylon Gaming BOTS Client - Protector: ENIGMA v3.140 - Complete analysis completed_
