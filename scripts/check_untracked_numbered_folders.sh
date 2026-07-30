#!/usr/bin/env bash
set -euo pipefail

# This script fails if there are untracked files or folders that start with two digits
# (e.g., `03_Recursion`) to help avoid accidentally forgetting to `git add` new folders.

untracked=$(git ls-files --others --exclude-standard | grep -E '(^|/)[0-9][0-9]_' || true)
if [ -n "$untracked" ]; then
  echo "Error: Found untracked numbered folders/files that may need to be tracked:"
  echo "$untracked"
  echo
  echo "Add them with: git add <path>"
  echo "Or update .gitignore if you intended to ignore them."
  exit 1
fi

exit 0
