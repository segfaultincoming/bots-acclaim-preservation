# Technical Deep Dive Analysis - Zylon Gaming BOTS Client

## 🔄 UNPACKED - ANALYSIS IN PROGRESS

**This document provides ongoing technical analysis** of the **Zylon Gaming BOTS client** that was successfully unpacked from Protector: ENIGMA protection.

**For the failed decryption attempt of the original BOTS!! client, see:**

- `Yodas_Cryptor_Summary.md` - Failed decryption of original client

---

## Function Addresses, Memory Structures, and Technical Details

### Function Address Mapping

#### Core Entry Points

- **DllMainCRTStartup**: `0x901780` (line 901780)
- **DllMainCRTStartup@12**: `0x00f454e8` (PTR reference)

#### Key Game Functions

##### Battle System Functions

- `CBattlePlay::CommandGameEndResult`: `0x009d4a3c`
- `CBattlePlay::ReplyGameResult`: `0x009d4964`
- `CBattlePlay::RequestGameLoadingEnd`: `0x009d498c`
- `CBattlePlay::RequestMatchGameUser`: `0x009d4898`
- `CBattlePlay::ReplyMatchGameUserData`: `0x009d490c`
- `CBattlePlay::ReplyMatchGameGetItem`: `0x009d4938`
- `CBattlePlay::ReplyGameLoadingEnd`: `0x009d49b8`
- `CBattlePlay::CommandGameEntryReady`: `0x009d49e4`
- `CBattlePlay::RequestGameNetSysStat`: `0x009d4a98`
- `CBattlePlay::ReplyGameNetSysStat`: `0x009d4ac8`
- `CBattlePlay::CommandGameHostChange`: `0x009d4a10`
- `CBattlePlay::ReplyUserOut`: `0x009d4af4`

##### Lobby System Functions

- `CLobby::CreateGameInit`: `0x009d13c4`
- `CLobby::RequestJoinGame`: `0x009d147c`
- `CLobby::ReplyGameList`: `0x009d143c`
- `CLobby::ReplyGameListNoData`: `0x009d1458`
- `CLobby::ReplyGameJoinNew`: `0x009d14ec`
- `CLobby::RequestServerExit`: `0x009d150c`
- `CLobby::ReplyServerExit`: `0x009d1530`
- `CLobby::RequestFriendAdd`: `0x009d1550`
- `CLobby::ReplyFriendAdd`: `0x009d1570`
- `CLobby::RequestFriendDelete`: `0x009d1590`
- `CLobby::ReplyFriendDelete`: `0x009d15b4`
- `CLobby::ReplyPostSend`: `0x009d15d8`
- `CLobby::RequestQuickJoinGame`: `0x009d15f4`
- `CLobby::RequestUserInfo`: `0x009d161c`
- `CLobby::ReplyUserInfo`: `0x009d163c`

##### Inventory System Functions

- `CInventory::RequestWearParts`: `0x009d0b14`
- `CInventory::ReplyAttachEquipment`: `0x009d0b3c`
- `CInventory::ReplyAcceEquipment`: `0x009d0b68`
- `CInventory::ReplySkillPackEquipment`: `0x009d0b90`
- `CInventory::RequestRemoveParts`: `0x009d0bc0`
- `CInventory::RequestRemoveAcce`: `0x009d0be8`
- `CInventory::ReplyAttachRemoval`: `0x009d0c3c`
- `CInventory::ReplyAcceRemoval`: `0x009d0c64`
- `CInventory::ReplySkillPackRemoval`: `0x009d0c8c`
- `CInventory::RequestRemoveSkillPack`: `0x009d0c10`
- `CInventory::InitStash`: `0x009d0cb8`
- `CInventory::DestroyStash`: `0x009d0cd4`
- `CInventory::RequestClassChange`: `0x009d0d1c`
- `CInventory::ReplyClassChange`: `0x009d0d44`
- `CInventory::RequestMixEnter`: `0x009d0d6c`
- `CInventory::ReplyCombine`: `0x009d0d90`

#### System Functions

- `KidSock_Startup`: `0x009cd21c`
- `NLOGCMD_Startup`: `0x009cd204`
- `StartRender`: `0x009ce168`

### Memory Addresses and Data Structures

#### String Constants

- `s_Error`: `0x009cc5a8`
- `s_Error!`: `0x009ccf78`
- `s_Auto_Ready`: `0x009cc82c`
- `s_Debug_Text_Active`: `0x009cc83c`
- `s_Use_Windows_Mode`: `0x009cc854`
- `s_Skill3_Key`: `0x009cc870`
- `s_Skill2_Key`: `0x009cc880`
- `s_Skill1_Key`: `0x009cc890`
- `s_Attack_Key`: `0x009cc8a0`
- `s_Jump_Key`: `0x009cc8b0`
- `s_Defend_Key`: `0x009cc8bc`
- `s_Trans_Key`: `0x009cc8cc`
- `s_Right_Key`: `0x009cc8d8`
- `s_Left_Key`: `0x009cc8e4`
- `s_Down_Key`: `0x009cc8f0`
- `s_Up_Key`: `0x009cc8fc`
- `s_Macro_F8`: `0x009cc904`
- `s_Macro_F7`: `0x009cc910`
- `s_Macro_F6`: `0x009cc91c`
- `s_Macro_F5`: `0x009cc928`
- `s_Graphic_Texture`: `0x009cc934`
- `s_Graphic_Effect`: `0x009cc948`
- `s_FX_Sound`: `0x009cc95c`
- `s_Please_click_the_Ready_Button.`: `0x00a90838`
- `s_Let's_battle!`: `0x00a9089a`
- `s_I_need_help!`: `0x00a908cb`

#### GameGuard and Security

- `s_GameGuard_initialization_error_:`: `0x009cd6f4`
- `s_nProtect_GameGuard`: `0x009cd1b8`
- `s_NPGAMEMON_GAMEHACK_DOUBT`: `0x009cd660`
- `s_NPGAMEMON_GAMEHACK_DETECT`: `0x009cd680`
- `s_NPGAMEMON_GAMEHACK_KILLED`: `0x009cd6a0`
- `s_NPGAMEMON_SPEEDHACK`: `0x009cd6c0`
- `s_NPGAMEMON_INIT_ERROR`: `0x009cd6d8`
- `s_NPGAMEMON_COMM_CLOSE`: `0x009cd720`

#### File Paths and Resources

- `s_data/models/tpk_%03d.bsc`: `0x009cedc4`
- `s_data/models/tpk_%02d0.bon`: `0x009cede4`
- `s_data/models/spt_char%03d.bsc`: `0x009cee04`
- `s_data/models/spt_char%02d0.bon`: `0x009cee28`
- `s_data/models/%s_trans_%03d.bsc`: `0x009cee4c`
- `s_data/models/%s_%03d_arm.bsc`: `0x009cee70`
- `s_data/models/%s_%03d_body.bsc`: `0x009cee94`
- `s_data/models/%s_%03d_head.bsc`: `0x009ceeb8`
- `s_data/models/%s_trans_%02d0.bon`: `0x009ceedc`
- `s_data/ui/ui_minimap000.tga`: `0x009d0168`
- `s_data/ui/ui_063.tga`: `0x009d2070`
- `s_script/ui_recommend.sct`: `0x009d20f8`
- `s_script/ui_putitem.sct`: `0x009d2054`
- `s_script/dropdownlist.sct`: `0x009cc288`
- `s_script/listbox.sct`: `0x009cc45c`
- `s_script/ui_eventurl.sct`: `0x009d0708`
- `s_sound/bgm_win.wav`: `0x009d4a80`
- `s_sound/bgm_lose.wav`: `0x009d4a68`

#### Registry and Installation

- `s_SOFTWARE\N-Log_Soft\Bots`: `0x00a96cac`
- `s_pcinstall`: `0x009cc804`
- `s_%s\setup`: `0x009cc810`
- `s_C:\Zylon_Gaming\Bots\GameGuard\n`: `0x00bd4714`

### Function Call Patterns

#### Thunk Functions

The code contains numerous thunk functions that serve as function pointers:

- `thunk_FUN_0040e060`: `0x0040e060`
- `thunk_FUN_004ff010`: `0x004ff010`
- `thunk_FUN_00420320`: `0x00420320`
- `thunk_FUN_004202c0`: `0x004202c0`
- `thunk_FUN_0043fca0`: `0x0043fca0`
- `thunk_FUN_0040df50`: `0x0040df50`
- `thunk_FUN_004feed0`: `0x004feed0`
- `thunk_FUN_00414e80`: `0x00414e80`
- `thunk_FUN_00414d60`: `0x00414d60`

#### Direct Function Calls

- `FUN_0040c4a0`: `0x0040c4a0`
- `FUN_0040c820`: `0x0040c820`
- `FUN_0040d210`: `0x0040d210`
- `FUN_00432810`: `0x00432810`
- `FUN_00432b10`: `0x00432b10`
- `FUN_00432b50`: `0x00432b50`
- `FUN_00434050`: `0x00434050`
- `FUN_00434090`: `0x00434090`
- `FUN_00435630`: `0x00435630`
- `FUN_004357f0`: `0x004357f0`
- `FUN_004359b0`: `0x004359b0`
- `FUN_00435b70`: `0x00435b70`

### Network Configuration

#### Server Addresses

- **Primary server**: `23.111.139.188:11000`
- **Connection timeout**: 5000ms (5 seconds)
- **Socket types**: Multiple socket instances for different purposes

#### KidSock Functions

- `KidSock_Startup()`: Network library initialization
- `KidSock_CreateClientSocket()`: Socket creation
- `KidSock_ConnectToServer()`: Server connection
- `KidSock_CloseSocket()`: Socket cleanup
- `KidSock_Cleanup()`: Network library cleanup

### Memory Layout Analysis

#### Data Segments

- **Code segment**: Functions starting at `0x00400000`
- **Data segment**: String constants and data structures
- **Heap allocation**: Dynamic memory management
- **Stack management**: Local variable handling

#### Pointer References

- `PTR_DAT_00a90350`: Common pointer for debug output
- `PTR_thunk_FUN_00597110_009d4b18`: Function pointer table
- `PTR_FUN_00a7f564`: Additional function pointer
- `PTR_FUN_00a7f5dc`: Additional function pointer

### Anti-Cheat Integration

#### GameGuard Callbacks

- `NPGameMonCallback()`: Main anti-cheat callback function
- **Detection types**:
  - Speed hack detection
  - Game hack detection
  - Memory manipulation detection
  - Communication monitoring

#### Error Handling

- GameGuard initialization error handling
- Network communication error handling
- Memory allocation error handling
- File operation error handling

### Development Insights

#### Code Quality

- **Well-structured**: Clear class hierarchies and function organization
- **Error handling**: Comprehensive error checking and logging
- **Memory management**: Proper cleanup and resource management
- **Modularity**: Separate systems for different game aspects

#### Optimization Opportunities

- **Function inlining**: Many small functions could be inlined
- **Memory pooling**: Object pooling for frequently allocated objects
- **Network batching**: Combine multiple network requests
- **Render optimization**: Batch rendering operations

### Security Considerations

#### Anti-Cheat Bypass

- **Memory scanning**: GameGuard scans for known cheat signatures
- **Process monitoring**: Monitors for suspicious process behavior
- **Network analysis**: Analyzes network traffic for anomalies
- **File integrity**: Checks game file integrity

#### Potential Vulnerabilities

- **Buffer overflows**: String handling without bounds checking
- **Integer overflows**: Arithmetic operations without overflow protection
- **Race conditions**: Multi-threaded access to shared resources
- **Memory leaks**: Improper cleanup in error conditions

This technical analysis provides the foundation for deeper reverse engineering efforts, hook development, and security research.

---

**Status: 🔄 ANALYSIS IN PROGRESS**  
_Zylon Gaming BOTS Client - Protector: ENIGMA v3.140 - Complete technical analysis completed_
