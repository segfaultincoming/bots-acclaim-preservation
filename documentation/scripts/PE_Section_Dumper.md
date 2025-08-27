# PE Section Dumper

## Overview

This script analyzes PE files and dumps all sections to `.bin` files for further analysis. It's specifically designed for analyzing unpacked game clients.

**Script Location**: `pe_section_dumper.py` (in project root directory)

## Usage

### Basic Usage (Dumps all sections)

```bash
# From project root directory
python pe_section_dumper.py unpacking/bout-zylon.dat
```

### Custom Output Directory

```bash
python pe_section_dumper.py unpacking/bout-zylon.dat -o my_sections
```

### Dump Specific Section Only

```bash
python pe_section_dumper.py unpacking/bout-zylon.dat -s .text
```

### Analysis Only (No Section Dumping)

```bash
python pe_section_dumper.py unpacking/bout-zylon.dat --no-dump
```

## Output

- **Sections**: Dumped to `results/pe_sections/` folder
- **Report**: Analysis report saved to `results/pe_analysis_report.txt`
- **Summary**: Section summary saved to `results/pe_sections/sections_summary.txt`

## Requirements

- Python 3.6+
- No external dependencies (uses only standard library)

## What It Does

1. **PE Header Analysis**: Parses PE headers and identifies entry points
2. **Section Analysis**: Lists all sections with properties
3. **Section Dumping**: Extracts each section to individual `.bin` files
4. **Entry Point Analysis**: Identifies where execution begins
5. **Report Generation**: Creates comprehensive analysis reports

## Use Cases

- **Game Client Analysis**: Extract code and data sections for reverse engineering
- **Binary Analysis**: Understand PE file structure and memory layout
- **Security Research**: Analyze executable sections for vulnerabilities
- **Reverse Engineering**: Prepare sections for tools like Ghidra or IDA Pro

## File Structure

```
BOTS/
├── pe_section_dumper.py          # Script (root directory)
├── unpacking/
│   └── bout-zylon.dat           # Target PE file
├── results/                      # Output directory
│   └── pe_sections/             # Dumped sections
└── documentation/
    └── scripts/                  # This documentation
        └── README_PE_Section_Dumper.md
```

## Running the Script

1. **Navigate to project root**: `cd /path/to/BOTS`
2. **Run the script**: `python pe_section_dumper.py unpacking/bout-zylon.dat`
3. **Check results**: Look in `results/pe_sections/` folder
4. **Review reports**: Check `results/pe_analysis_report.txt`
