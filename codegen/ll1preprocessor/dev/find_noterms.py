import re


def find_symbols(strings):
    """
    Extract all strings enclosed in <> from a list of strings.

    Parameters:
    strings (list): A list of strings.

    Returns:
    list: A list of strings enclosed in <>.
    """
    pattern = r"<[^>]+>"
    enclosed_strings = []

    for string in strings:
        enclosed_strings.extend(re.findall(pattern, string))

    return enclosed_strings

def strip_angle_brackets(strings):
    """
    Removes the < and > characters from each string in a list.

    Parameters:
    strings (list): A list of strings enclosed in angle brackets.

    Returns:
    list: A list of strings without angle brackets.
    """
    return [s[1:-1] if s.startswith('<') and s.endswith('>') else s for s in strings]


def read_file(file_path):
    """
    Reads the contents of a file into a list, where each element is a line from the file.

    Parameters:
    file_path (str): The path to the file.

    Returns:
    list: A list containing the lines of the file.
    """
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()
            # Remove any trailing newlines or whitespace
            lines = [line.strip() for line in lines]
        return lines
    except FileNotFoundError:
        print(f"Error: The file at {file_path} was not found.")
        return []
    except Exception as e:
        print(f"An error occurred: {e}")
        return []

# Example usage
data = read_file("processed.txt")
raw = find_symbols(data)

res = strip_angle_brackets(list(set(raw)))
print(res)