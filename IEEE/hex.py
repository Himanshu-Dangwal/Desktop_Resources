# import struct

# def hex_to_int32(hex_value):
#     """Convert a hex string to a 32-bit integer."""
#     return int(hex_value, 16)

# def int32_to_hex(int_value):
#     """Convert a 32-bit integer to an 8-character hex string, lowercase."""
#     return f'{int_value & 0xFFFFFFFF:08x}'

# def execute_command(commands, lut_tables, initial_value):
#     # Initialize C with the integer representation of the initial float
#     C = [initial_value]

#     for command in commands:
#         parts = command.split()
#         cmd_type = parts[0]

#         if cmd_type == 'C':
#             # Constant declaration, store the constant as an integer
#             h = parts[1]
#             C.append(hex_to_int32(h))

#         elif cmd_type == 'L':
#             # Look-Up Table command
#             i = int(parts[1])
#             j = int(parts[2])
#             b = int(parts[3])
#             mask = (C[0] >> j) & ((1 << b) - 1)
#             C.append(lut_tables[i][mask])

#         elif cmd_type == 'N':
#             # NAND command
#             i = int(parts[1])
#             j = int(parts[2])
#             nand_result = ~(C[i] & C[j]) & 0xFFFFFFFF
#             C.append(nand_result)

#         elif cmd_type == 'F':
#             # Fused Multiply-Add command
#             i = int(parts[1])
#             j = int(parts[2])
#             k = int(parts[3])
#             # Perform FMA using integer values for multiplication and addition
#             fma_result = C[i] * C[j] + C[k]
#             # Convert to 32-bit integer format
#             C.append(fma_result & 0xFFFFFFFF)

#     # Return the hex representation of the last command's result
#     return C[-1]

# def main():
#     import sys
#     input = sys.stdin.read
#     data = input().splitlines()

#     index = 0
#     T = int(data[index])
#     index += 1
#     results = []

#     for _ in range(T):
#         initial_hex = data[index]
#         initial_value = hex_to_int32(initial_hex)
#         index += 1
        
#         L = int(data[index])
#         index += 1
        
#         lut_tables = []
        
#         for __ in range(L):
#             line = data[index].split()
#             size = int(line[0])
#             values = [hex_to_int32(h) for h in line[1:size + 1]]
#             lut_tables.append(values)
#             index += 1
        
#         Q = int(data[index])
#         index += 1
        
#         commands = []
        
#         for __ in range(Q):
#             commands.append(data[index])
#             index += 1
        
#         final_result = execute_command(commands, lut_tables, initial_value)
#         results.append(final_result)

#     for result in results:
#         print(int32_to_hex(result))

# if __name__ == "__main__":
#     main()
import struct

def hex_to_int32(hex_value):
    """Convert a hex string to a 32-bit integer."""
    return int(hex_value, 16)

def int32_to_hex(int_value):
    """Convert a 32-bit integer to an 8-character hex string, lowercase."""
    return f'{int_value & 0xFFFFFFFF:08x}'

def int32_to_float(int_value):
    """Convert a 32-bit integer to a single-precision floating-point number."""
    return struct.unpack('!f', struct.pack('!I', int_value))[0]

def float_to_int32(float_value):
    """Convert a single-precision floating-point number to a 32-bit integer."""
    return struct.unpack('!I', struct.pack('!f', float_value))[0]

def execute_commands(commands, lookup_tables, initial_hex_value):
    # Initialize the command results with the integer representation of the initial hex value
    command_results = [initial_hex_value]

    for command in commands:
        parts = command.split()
        command_type = parts[0]

        if command_type == 'C':
            # Constant declaration, store the constant as an integer
            hex_value = parts[1]
            command_results.append(hex_to_int32(hex_value))

        elif command_type == 'L':
            # Look-Up Table (LUT) command
            table_index = int(parts[1])
            bit_start = int(parts[2])
            bit_length = int(parts[3])
            mask = (command_results[0] >> bit_start) & ((1 << bit_length) - 1)
            command_results.append(lookup_tables[table_index][mask])

        elif command_type == 'N':
            # NAND command
            index_1 = int(parts[1])
            index_2 = int(parts[2])
            nand_result = ~(command_results[index_1] & command_results[index_2]) & 0xFFFFFFFF
            command_results.append(nand_result)

        elif command_type == 'F':
            # Fused Multiply-Add (FMA) command
            multiplicand_index = int(parts[1])
            multiplier_index = int(parts[2])
            addend_index = int(parts[3])
            # Convert selected integer values to floating-point numbers
            multiplicand = int32_to_float(command_results[multiplicand_index])
            multiplier = int32_to_float(command_results[multiplier_index])
            addend = int32_to_float(command_results[addend_index])
            # Perform FMA: (multiplicand * multiplier) + addend
            fma_result = multiplicand * multiplier + addend
            # Convert the result back to a 32-bit integer and store it
            command_results.append(float_to_int32(fma_result))

    # Return the hex representation of the last command result
    return command_results[-1]

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    index = 0
    test_cases = int(data[index])
    index += 1
    results = []

    for _ in range(test_cases):
        initial_hex = data[index]
        initial_value = hex_to_int32(initial_hex)
        index += 1
        
        num_tables = int(data[index])
        index += 1
        
        lookup_tables = []
        
        for __ in range(num_tables):
            line = data[index].split()
            table_size = int(line[0])
            table_values = [hex_to_int32(hex_value) for hex_value in line[1:table_size + 1]]
            lookup_tables.append(table_values)
            index += 1
        
        num_commands = int(data[index])
        index += 1
        
        commands = []
        
        for __ in range(num_commands):
            commands.append(data[index])
            index += 1
        
        final_result = execute_commands(commands, lookup_tables, initial_value)
        results.append(final_result)

    for result in results:
        print(int32_to_hex(result))

if __name__ == "__main__":
    main()
