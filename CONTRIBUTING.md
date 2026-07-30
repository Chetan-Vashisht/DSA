Pre-commit hook

To avoid accidentally leaving new numbered folders (like `03_Recursion`) untracked,
install the provided helper as a local pre-commit hook:

```sh
# from repo root
ln -sf ../../scripts/check_untracked_numbered_folders.sh .git/hooks/pre-commit
chmod +x scripts/check_untracked_numbered_folders.sh
```

This will cause commits to fail if there are untracked two-digit-prefixed folders/files,
reminding you to `git add` them or update `.gitignore` intentionally.
