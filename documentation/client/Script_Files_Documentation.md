# BOTS Script Files Documentation

## Overview

The `/script` directory contains configuration files that define game behavior, UI layouts, and data structures. These files are crucial for understanding how the game operates.

## File Types

### .sct Files (Script Configuration Text)

UI layout and interaction definitions with precise pixel positioning.

### .bin Files (Binary Data)

Compiled game data including items, maps, strings, and game logic.

### .sys Files (System Configuration)

System-level configuration and information files.

## Key Script Files Analysis

### UI Configuration Files

#### ui_lobby.sct

Main lobby interface configuration:

```
[Main Button]
BattleCreateGame    26  16  187 71   - Create battle room
PlanetCreateGame    26  16  187 71   - Create planet mode room
BaseCreateGame      26  16  187 71   - Create base mode room
BattleQuickJoin     201 16  361 71   - Quick join battle
PlanetQuickJoin     201 16  361 71   - Quick join planet
BaseQuickJoin       201 16  361 71   - Quick join base
TradeBoard          375 16  536 71   - Trading board access
MyInfo              26  555 139 587  - Player information
Shop                159 555 272 587  - Game shop
```

#### ui_shop.sct

Shop interface with item categories:

- Recommended items (추천)
- Parts (부품)
- Accessories (액세서리)
- Packages (패키지)
- Events (이벤트)

#### ui_inventory.sct

Inventory management system:

```
[Main Button]
Wear           421 513 475 534 - Equip item
OpenStash      552 349 643 367 - Open storage
Cash           342 555 465 587 - Cash shop access
AttachRemove   563 307 633 328 - Remove attachments
```

#### dropdownlist.sct

Game mode and configuration dropdowns:

- Lobby room creation options
- Game rule selections
- Level limitations
- Map selections

### Data Files

#### item.bin (1.1MB)

Compiled item database containing:

- Item properties and stats
- Equipment specifications
- Cash shop items
- Upgrade information

#### shop.bin (106KB, 20 lines)

Shop configuration and pricing:

- Item availability
- Category organization
- Pricing structures
- Special offers

#### string.bin (25KB)

Localized text strings for UI elements and game messages.

#### map\_\*.bin Files

Map configuration data:

- `map_battle.bin` (1010B) - Battle mode maps
- `map_base.bin` (1.5KB) - Base mode maps
- `map_planet.bin` (4.5KB) - Planet/dungeon maps

### System Configuration

#### bulinfo.sys (988B)

Bullet/projectile information and ballistics data.

#### ftinfo.sys (4.4KB, 4 lines)

File type information and associations.

#### env_cloc.sys (326B)

Environment clock/timing configuration.

### Game Data

#### mercinfo.bin (1.6KB)

Mercenary/character information:

- Character stats
- Abilities and skills
- Transformation data

#### skillpk.bin (1.9KB)

Skill and special ability definitions.

#### slangs.bin (6.7KB)

Profanity filter and chat moderation.

#### check.bin (13KB)

Data integrity and validation checksums.

## Script Format Analysis

### Coordinate System

UI scripts use absolute pixel positioning:

- Format: `Left Top Right Bottom X Y`
- Collision rectangles define clickable areas
- Draw positions specify sprite rendering location

### Image References

Scripts reference texture files in the data directory:

```
data/ui/ui_lobby_btn_mkroom_battle.dds
data/ui/ui_205.tga
```

### Button States

UI elements support multiple states (normal, hover, pressed, disabled):

- Image pieces: `1 4` indicates sprite sheet coordinates
- Multiple collision rectangles for different states

### Localization

Korean text embedded in configuration files:

- `추천` (Recommended)
- `부품` (Parts)
- `액세서리` (Accessories)
- `패키지` (Package)
- `이벤트` (Event)

## Configuration Patterns

### Tab Systems

Many UI screens use tab-based navigation:

```
[Tab Button]
부품     414 16  498 44  - Parts tab
액세서리  499 16  583 44  - Accessories tab
패키지    584 16  668 44  - Package tab
이벤트    669 16  754 44  - Event tab
```

### List Boxes

Dropdown and selection lists with scroll functionality:

```
[ListBox Init]
MaxPage: 5
ScrollBar Area: defined rectangles
Item dimensions and positioning
```

### Button Categories

Buttons organized by function:

- Main navigation buttons
- Sub-buttons for consent/refusal
- Tab switching buttons
- Action buttons (OK, Cancel, Apply)

## Data Relationships

### Cross-References

- UI scripts reference image files in `/data/ui/`
- Map scripts connect to map files in `/data/maps/`
- Item scripts link to model files in `/data/models/`

### Version Control

Scripts include version numbers and patch information matching the main version.txt timeline.

---

_Documentation covers 50+ script files_
_Last updated: 2025-08-22_
