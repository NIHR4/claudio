from openpyxl import load_workbook

# Load the workbook and select the sheet
workbook = load_workbook("C:\\Users\\andre\\Downloads\\FinalParsingTable.xlsm")  # Replace with your file name
sheet = workbook["Parsing Table"]  # Replace with your sheet name

# Define the range to extract from
start_cell = "B2"
end_cell = "AJ35"
range_to_extract = sheet[start_cell:end_cell]

# Extract non-empty cells and flatten to a list
non_empty_cells = [cell.value for row in range_to_extract for cell in row if cell.value not in ('-', None)]
unique = set(non_empty_cells)

# Write each element to a new line in the file
with open("processed.txt", "w", encoding="utf-8") as file:
    for item in unique:
        file.write(f"{item}\n")
