# Scripts Documentation

## Overview

This folder contains documentation for various analysis and reverse engineering scripts used in the BOTS game client research project.

## Available Scripts

### PE Section Dumper

- **Script**: `pe_section_dumper.py` (located in root directory)
- **Documentation**: [PE_Section_Dumper.md](PE_Section_Dumper.md)
- **Purpose**: Analyzes PE files and dumps all sections to `.bin` files for further analysis
- **Use Case**: Analyzing unpacked game clients, extracting code and data sections

## Script Categories

### Analysis Tools

- **PE Analysis**: Tools for analyzing Portable Executable files
- **Section Extraction**: Scripts for dumping binary sections
- **Report Generation**: Automated analysis report creation

### Reverse Engineering

- **Binary Analysis**: Understanding file structure and memory layout
- **Code Extraction**: Preparing sections for tools like Ghidra or IDA Pro
- **Security Research**: Analyzing executable sections for vulnerabilities

## Usage

All scripts are located in the root directory of the project. This folder contains only the documentation.

To use a script:

1. Navigate to the project root directory
2. Run the script with appropriate parameters
3. Check the `/results/` folder for output files

## Requirements

- Python 3.6+
- No external dependencies (scripts use only Python standard library)
- Appropriate input files (PE files, game clients, etc.)

## Output Structure

Scripts generate output in the `/results/` folder with the following structure:

```
results/
├── pe_sections/          # PE section dumps
├── pe_analysis_report.txt # Analysis reports
└── [other outputs]       # Additional script outputs
```

---

_Script documentation for BOTS game client reverse engineering project_
