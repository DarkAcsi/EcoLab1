import os

for folder in os.listdir():
    if folder.startswith('cmake-build'):
        with open(f'{folder}/build.ninja', 'r') as file:
            text = file.read()

            text = text.replace(' -MDd', '').replace(' -MD', '').replace(' -Zi', '')

        with open(f'{folder}/build.ninja', 'w') as file:
            file.write(text)
