import pandas as pd

file_path = 'DFA.xlsx'
dfa_data = pd.read_excel(file_path)

print("Column names:", dfa_data.columns.tolist())


def generate_state_code(state_name, transitions):
    
    code = f'State q{state_name};\n'
    code += f'q{state_name}.setName("q{state_name}");\n'
    for symbol, target_state in transitions.items():
        code += f'q{state_name}.addTransition(\'{symbol}\', "q{target_state}");\n'
    code += f'fsm.addState(q{state_name});'
    #code += f'_states.push_back(std::move(q{state_name}));\n\n'
    return code

def generate_dfa_code(dfa_states, alphabet):
    dfa_code = ""
    for state, transitions in dfa_states.items():
        dfa_code += generate_state_code(state, transitions)
    
    
    # dfa_code += f"std::vector<State> states {{{', '.join(f'q{item}' for item in dfa_states.keys())}}};"
    '''
    dfa_code += 'DFA dfa;\n'
    for state in dfa_states.keys():
        dfa_code += f'dfa.addState("{state}");\n'
    '''
    return dfa_code

# Process the data from the Excel file into a dictionary
dfa_states = {}
symbols = dfa_data.columns[1:]  # Assuming the first column is 'FromState'

# Convert symbols to strings if necessary
symbols = [str(symbol) for symbol in symbols]

for index, row in dfa_data.iterrows():
    state = row[dfa_data.columns[0]]  # Update to match the actual name of the first column
    if isinstance(state, float):
        state = int(state)
    transitions = {}
    for symbol in symbols:
        symbol_str = str(symbol)
        if symbol_str in row:
            target_state = row[symbol_str]
            if pd.notna(target_state):  
                if isinstance(target_state, float):
                    target_state = int(target_state)
                transitions[symbol_str] = target_state
    
    dfa_states[state] = transitions

cpp_code = generate_dfa_code(dfa_states, symbols)

output_file = 'generated_dfa_code.cpp'
with open(output_file, 'w') as f:
    f.write(cpp_code)

print(f"Generated C++ code saved to {output_file}")