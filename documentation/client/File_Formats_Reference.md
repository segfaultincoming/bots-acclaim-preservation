# BOTS File Formats Reference

## Model and Animation Formats

### .ba0 / .ba2 Files

**Primary model geometry files**

- `.ba0` - Base geometry data (possibly vertices/faces)
- `.ba2` - Secondary geometry or texture coordinates
- Always paired together for complete models
- Used for characters, weapons, and objects

### .bb0 / .bb2 Files

**Secondary model components**

- Additional geometry layers or detail levels
- Often used for character body parts
- May contain collision geometry or LOD data

### .bon Files

**Bone/Skeleton data**

- Animation bone structure
- Character rigging information
- Joint hierarchy and constraints
- Essential for character animation

### .bsc Files

**Model script/configuration**

- Model behavior definitions
- Animation state machines
- Attachment points and constraints
- Links model components together

## Map and Environment Formats

### .map Files

**Main map configuration**

- Map metadata and settings
- Spawn points and objectives
- Environment parameters
- Links to associated geometry files

### .oa0 / .oa2 / .ob0 / .ob2 etc.

**Map geometry chunks**

- Large maps split into grid sections
- Follows naming pattern: `0000.xx0` / `0000.xx2`
- Letter suffix (a,b,c...) indicates grid position
- Number suffix (0,2) indicates primary/secondary data

### .obj Files

**Object placement data**

- Static object positions
- Interactive element locations
- Environment decoration placement
- Links to model files

### .val Files

**Property/value definitions**

- Object properties and parameters
- Trigger conditions and behaviors
- Game logic configuration
- Numeric data storage

### .flu Files

**Fluid/dynamic data**

- Possibly particle system data
- Dynamic environment elements
- Atmospheric effects
- Weather system data

## Effect and Particle Formats

### .eff Files

**Effect configuration**
Text-based configuration files defining particle effects:

```
gravity : 1
link : 0
power : 0.500000
minrange : 100.000000
range : 30.000000
startspeed : 0.500000
everageweight : 100.000000
particlenum : 80
framenum : 30
tailnum : 1
texnum : 1
tex0 : lighta.tga
```

Parameters:

- `gravity` - Gravitational effect on particles
- `power` - Effect intensity
- `range` - Effect radius/distance
- `particlenum` - Number of particles to generate
- `framenum` - Animation frame count
- `texnum` - Number of textures used
- `tex0` - Primary texture reference

## User Interface Formats

### .sct Files

**Script Configuration Text**
Human-readable UI layout definitions:

```
[Button Name]
;Description    Left  Top  Right Bottom  X    Y    ImageX ImageY  File
BattleCreate    26    16   187   71      26   16   1      4       data/ui/button.tga
```

### .tga Files

**Targa image format**

- UI textures and graphics
- Character portraits
- Menu backgrounds
- Uncompressed or RLE compressed

### .dds Files

**DirectDraw Surface**

- Compressed textures
- Modern UI elements
- Mipmapped textures for performance
- DXT compression formats

### .jpg Files

**JPEG images**

- Advertisement banners
- Large background images
- Compressed promotional content

## Data and Configuration Formats

### .bin Files

**Binary data files**

- Compiled game databases
- Item definitions and stats
- Map configurations
- String tables and localization

Common .bin files:

- `item.bin` - Item database
- `shop.bin` - Shop configuration
- `string.bin` - Text strings
- `mercinfo.bin` - Character data
- `skillpk.bin` - Skill definitions

### .sys Files

**System configuration**

- Engine parameters
- File type associations
- System-level settings
- Performance tuning

### .dat Files

**Data archive**

- `bots.dat` - Main game data archive
- Compressed file collections
- Game asset packaging

## Audio Formats

### .wav Files

**Wave audio**

- Uncompressed audio
- Sound effects and voice
- Background music
- High quality audio for critical sounds

## Executable and Library Formats

### .exe Files

**Executable programs**

- `bots.exe` - Main game executable
- `bots-dat.exe` - Data extraction utility
- Windows PE format

### .dll Files

**Dynamic link libraries**

- `boutcmd.dll` - Game command processing
- `nlogcmd.dll` - Network/logging functions
- `mac3r.dll` - Security/authentication
- `binkw32.dll` - Video codec (Bink)
- `zlib1.dll` - Compression library

### .ini Files

**Configuration files**

- Text-based settings
- GameGuard configuration
- Server settings
- User preferences

## Archive and Patch Formats

### .bat Files

**Batch scripts**

- Game launcher
- Update procedures
- System setup

## Naming Conventions

### Character Models

- `[type]_[number]_[part].[ext]`
- Type: az, gr, hs, tpk (character classes)
- Number: 3-digit identifier
- Part: head, arm, body, trans (transformation)

### Team Variants

- `_teamb` - Blue team variant
- `_teamr` - Red team variant
- Default - Neutral/single player

### Map Files

- `planet[##]_dun[##]` - Planet dungeons
- `planet_elite[##]` - Elite maps
- `base_[name]` - Base/lobby maps

### Effect Files

Pattern-based naming:

- Color indicators: blue, red, green, white
- Effect types: attack, hit, transform, basic
- Intensity levels: a, b, c, d (increasing power)

## File Relationships

### Model Dependencies

```
character_100.ba0  ← Primary geometry
character_100.ba2  ← Texture coordinates
character_100.bon  ← Bone structure
character_100.bsc  ← Configuration
```

### Map Dependencies

```
mapname.map        ← Main configuration
0000.oa0/oa2      ← Geometry chunks
0000.obj          ← Object placement
0000.val          ← Properties
```

### Effect Dependencies

```
effect.eff        ← Configuration
texture.tga       ← Referenced texture
sound.wav         ← Associated audio
```

---

_Reference covers 10+ primary file formats_
_Based on analysis of 5000+ game files_
_Last updated: 2025-08-22_
