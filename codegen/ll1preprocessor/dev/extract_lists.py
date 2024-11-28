from openpyxl import load_workbook
import re
def extract_nonterminals(workbook):
    sheet = workbook["Parsing Table"]  # Replace with your sheet name
    start = 2
    end = 35
    cell_range = [f"A{i}" for i in range(start, end+1)]  # A2:A36
    return [sheet[cell].value for cell in cell_range]

def extract_terminals(workbook):
    sheet = workbook["Parsing Table"]
    cell_range = sheet["B1":"AJ1"]
    return [cell.value for row in cell_range for cell in row]

def extract_unique_productions(workbook):
    start_cell = "B2"
    end_cell = "AJ35"
    sheet = workbook["Parsing Table"]
    range_to_extract = sheet[start_cell:end_cell]
    non_empty_cells = [cell.value for row in range_to_extract for cell in row if cell.value not in ('-', None)]
    return list(set(non_empty_cells))

def get_enclosed_items(strings):
    pattern = r"<([^>]+)>"
    enclosed_strings = []
    for string in strings:
        enclosed_strings.extend(re.findall(pattern, string))

    return enclosed_strings



workbook = load_workbook("C:\\Users\\andre\\Downloads\\FinalParsingTable.xlsm")
known_nonterminals = extract_nonterminals(workbook)
productions = extract_unique_productions(workbook)
all_enclosed_items = get_enclosed_items(productions)

terminals = list(set([i for i in all_enclosed_items if i in known_nonterminals]))
nonterminals = [i for i in all_enclosed_items if i not in known_nonterminals]

print(f'terminals = {terminals}')
#print(nonterminals)
print(f'nonterminals = {extract_terminals(workbook)}')