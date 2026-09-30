**4 in 1 Master C Program**
A modular, interactive command-line application written in C that consolidates four foundational programming utilities into a unified, menu-driven interface.

**Features**
**1. Pattern Printing Engine**
Generates dynamic geometric and typographic shapes based on user-defined dimensions:

Hollow Square

Letter 'I' (with dynamic symmetry scaling for odd/even values)

Letter 'T'

Triangles: Lower Left, Lower Right, Upper Right, and Upper Left

**2. Caesar Cipher Text Encryption**
Lightweight character-shift cipher that encrypts full input strings (including spaces) by advancing ASCII values.

**3. Number Guessing Game**
Pseudo-random number generator (rand(), srand()) producing values between 1 and 100.

Real-time directional feedback ("Higher number please" / "Lower number please") and an attempt counter.

**4. Snake, Water, Gun Game**
Three-round match against an automated computer opponent.

Implements core game logic:

Gun beats Snake

Snake beats Water

Water beats Gun

Tracks cumulative scores and outputs the final result (Win / Loss / Draw).

**Input Validation & Robustness**
*Buffer Clearing:* Utilizes non-blocking input stream flush routines (getchar()) to prevent infinite looping on invalid non-integer inputs.

*Case Normalization:* Automatically converts uppercase inputs to lowercase in interactive prompts (e.g., 'S' to 's' in Snake-Water-Gun).

*Boundary Checks:* Validates dimensions and menu choices before triggering subroutines.
