import os

def rename_files(directory, prefix='', suffix=''):
    # Change the working directory to the specified path
    os.chdir(directory)

    # List all files in the directory
    for filename in os.listdir('.'):
        # Check if it's a file (not a directory)
        if os.path.isfile(filename):
            # Split the filename into the name and extension
            name, ext = os.path.splitext(filename)

            # Create the new filename
            new_filename = f"{prefix}{name}{suffix}{ext}"

            # Rename the file
            os.rename(filename, new_filename)

            print(f'Renamed: {filename} -> {new_filename}')

# Example usage with dynamic input
def main():
    # Get user input for the directory, prefix, and suffix
    directory = input("Enter the directory path (default: './'): ") or './'
    prefix = input("Enter a prefix (default: ''): ") or ''
    suffix = input("Enter a suffix (default: ''): ") or ''

    # Call the rename function
    rename_files(directory, prefix, suffix)

if __name__ == "__main__":
    main()
