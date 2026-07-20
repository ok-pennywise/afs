#!/usr/bin/env python3

import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
SRC = ROOT / "src"

cpp_files = sorted(str(f) for f in SRC.rglob("*.cpp"))

if not cpp_files:
    print(f"No .cpp files found under {SRC}")
    sys.exit(1)

cmd = [
    "g++",
    "-std=c++20",
    "-O2",
    *cpp_files,
    "-I" + str(SRC / "flight"),
    "-o",
    str(ROOT / "firmware"),
]

print("Compiling:")
print(" ".join(cmd))

subprocess.run(cmd, check=True)

print("\n✅ Build successful.")