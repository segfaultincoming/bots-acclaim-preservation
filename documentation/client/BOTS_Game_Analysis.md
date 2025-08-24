# BOTS Game Reverse Engineering Analysis

## Overview

BOTS is a 3D mech action game that appears to have been developed around 2006-2008 based on the patch history. The game features robot combat, various game modes, and an online multiplayer system.

## Game Information

- **Developer**: NLOG Soft
- **Current Version**: v0.51 (based on version.txt)
- **Engine**: Custom DirectX 9.0+ based engine
- **Anti-Cheat**: GameGuard protection system
- **Setup Version**: 20060706

## Directory Structure Analysis

### Root Directory

- `bots.exe` - Main game executable
- `bots.dat` - Main game data file
- `boutcmd.dll` - Command processing library
- `binkw32.dll` - Bink video codec (RAD Game Tools)
- Various other DLLs for networking, sound, and game logic

### /data Directory - Game Assets

Contains all visual and audio assets organized by type:

#### /data/ads

- Advertisement banners for main menu, login, and lobby
- Formats: .jpg, .tga

#### /data/bases

- Base/character model files
- Multiple team variants (team A, team B, team R)
- File formats: .ba0, .ba2, .bb0, .bb2, .bon, .bsc
- Naming convention suggests different character classes:
  - `base_cashmerc##` - Cash mercenary characters
  - `base_merc##` - Regular mercenary characters
  - `base_object##` - Base objects/structures

#### /data/effects

- **233+ effect files** (.eff format)
- Particle system configurations
- Attack effects, environmental effects, transformations
- Categories include:
  - Attack effects (various colors: blue, green, red, white)
  - Impact/hit effects
  - Transform/special ability effects
  - Environmental effects (flames, ice, lightning)
  - UI feedback effects

#### /data/maps

- **44 different maps** organized by type:
  - `base_*` - Base/lobby maps
  - `planet##_dun##` - Planet dungeon maps (numbered 01-20)
  - `planet_elite##` - Elite/special maps
  - Special maps: wasteland, deathvalley, moongate, etc.
- File formats: .oa0, .oa2, .ob0, .ob2, .map, .obj, .val, .flu
- Maps appear to be split into multiple chunk files (0000.xx format)

#### /data/models

- **4000+ model files** for characters, weapons, and objects
- Character parts organized by type:
  - Heads: `##_head.ba0/.ba2/.bsc`
  - Arms: `##_arm.ba0/.ba2/.bsc`
  - Bodies: `##_body.ba0/.ba2/.bsc`
  - Transformations: `##_trans_##.ba0/.ba2/.bon/.bsc`
- Weapon/item models: `wing_##`, `mini_##`, `fg_##`, `pdi_##`
- Team-specific variants and color schemes

#### /data/monster

- Monster/enemy models for PvE content
- Organized by planet: `planet##_mon##.ba0/.ba2/.bon/.bsc`
- Boss variants: `planet##_boss##.ba0/.ba2/.bon/.bsc`

#### /data/ui

- User interface graphics
- Main UI elements and HUD components
- Formats: .tga, .dds
- Subdirectories:
  - `/gameui` - In-game UI elements
  - `/text` - Text/font textures

### /script Directory - Game Configuration

Contains binary and text configuration files:

#### Key Script Files

- `*.sct` files - UI layout and button definitions
- `*.bin` files - Compiled game data (items, maps, strings, etc.)
- `*.sys` files - System configuration files

#### UI Script Analysis

Scripts define precise UI element positioning and functionality:

- Button collision rectangles
- Image sprite positions
- Text positioning
- Game mode configurations
- Dropdown menus and interface elements

#### Notable Scripts

- `ui_lobby.sct` - Main lobby interface
- `ui_shop.sct` - In-game shop system
- `ui_inventory.sct` - Inventory management
- `dropdownlist.sct` - Game mode selection
- `item.bin` - Item database
- `shop.bin` - Shop configuration

### /sound Directory

- **330 audio files** (.wav format)
- Organized by character types and actions:
  - Character movement sounds (walk, run, jump, land)
  - Combat sounds (attack, hit, break, down)
  - Transformation sounds
  - Background music (BGM files)
  - UI feedback sounds

## Game Mechanics Analysis

### Character Types

Based on file naming conventions, the game features multiple robot types:

- **AZ** - Assault type robots
- **GR** - Guard/Tank type robots
- **HS** - High-Speed type robots
- **TPK** - Unknown type (possibly special/unique)

### Transformation System

- Characters have base forms and transformation modes
- Multiple transformation levels per character
- Special "unique transformation" (uqtrans) variants
- Sound effects indicate transformation sequences

### Game Modes

From script analysis:

- **Battle Mode** - PvP combat
- **Planet Mode** - PvE dungeon exploration
- **Base Mode** - Base defense/capture

### Map System

- Numbered planet maps (01-20) with dungeon variants
- Elite maps for special content
- Environmental variety (wasteland, ice, space, etc.)
- Large maps split into multiple data chunks

### Item/Equipment System

- Multiple equipment slots per character
- Cash shop items (premium content)
- Team-specific variants (Red vs Blue teams)
- Upgrade/enhancement system indicated by numbered variants

## File Format Analysis

### Model Formats

- `.ba0/.ba2` - Primary model geometry files
- `.bb0/.bb2` - Secondary model components
- `.bon` - Bone/skeleton data
- `.bsc` - Model script/configuration

### Map Formats

- `.map` - Main map configuration
- `.oa0/.oa2` etc. - Map geometry chunks
- `.obj` - Object placement data
- `.val` - Values/properties
- `.flu` - Possibly fluid/particle data

### Effect Format

- `.eff` - Effect configuration files
- Particle system parameters (gravity, speed, texture references)

## Network Architecture

- Client-server architecture with login validation
- Anti-cheat integration (GameGuard)
- Server IP configuration system
- User authentication and session management

## Development Timeline

Based on version.txt patch history:

- **2006/01/26** - Initial development by NLOG Soft
- **2006-2008** - Active development period with 66 documented patches
- **Last Update**: 2008/04/29 - Patch version 066

## Security Features

- GameGuard anti-cheat system
- File integrity checking
- Network protocol validation
- Hacking detection and prevention

## Technical Requirements

- DirectX 9.0 or higher
- Windows platform (evidence of Win32 architecture)
- Network connectivity for online play
- 3D graphics card support

---

_Analysis completed on: 2025-08-22_
_Files analyzed: 5000+ game assets across multiple directories_
