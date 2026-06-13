# Academic


github linux error starting
Step 1 — Generate a token on GitHub:

Go to GitHub.com → Settings → Developer settings → Personal access tokens → Tokens (classic)
Click "Generate new token (classic)"
Give it a name, set expiration, and check the repo scope
Click Generate token and copy it immediately (you won't see it again)

# Remove the existing broken remote
git remote remove origin

# Add it back with your token embedded in the URL
git remote add origin https://YOUR_TOKEN@github.com/Mohammadkamrulhassan/Academic.git

# Now push
git push -u origin main
