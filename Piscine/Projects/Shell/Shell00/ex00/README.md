# File `z`

This project creates a file named `z` that returns `"Z"` followed by a new line when used with the `cat` command.

## 📄 Purpose

To demonstrate how to create a file that outputs `Z\n` when read using standard Unix tools.

---

## ⚙️ Method 1: Manual File Creation (Simple and Direct)

### Steps

1. **Create the file:**
```bash
touch z
```

2. Edit the file using vim (or any text editor):
```bash
vim z
```

3. Inside the editor, type the single letter: (click i to edit)
```
Z
```
Then press Enter once to add a new line.

Now save and exit by typing:
```
:wq
```
4. Check the content with cat:

```bash
cat z
```
✅ Expected Output
```bash
Z
```
