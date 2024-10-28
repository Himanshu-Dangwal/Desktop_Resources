import csv
import sys
from collections import defaultdict

def parse_csv(input_stream):
    """ Parses CSV input from the standard input stream and returns a list of records. """
    reader = csv.reader(input_stream)
    records = []
    for row in reader:
        # Clean up the row to handle quotes properly and filter out empty rows
        if len(row) < 6:
            continue  # Skip incomplete rows
        record = {
            "Event ID": row[0],
            "Event Title": row[1],
            "Acronym": row[2],
            "Project Code": row[3],
            "3 Digit Project Code": row[4],
            "Record Type": row[5]
        }
        records.append(record)
    return records

def process_events(records):
    """ Processes the records and applies the exclusion criteria. """
    parent_events = {}
    children_map = defaultdict(list)
    
    # Organize records into parents and children
    for record in records:
        event_id = record["Event ID"]
        event_type = record["Record Type"]
        acronym = record["Acronym"]

        if acronym:  # Only consider records with an acronym
            if event_type == "Parent Event":
                parent_events[event_id] = record
            elif event_type == "IEEE Event":
                children_map[record["Event ID"]].append(record)

    # Build serialized sets
    serialized_sets = defaultdict(list)
    
    for child_id, child_record in children_map.items():
        parent_id = child_record[0]["Event ID"].split("_")[0]  # Assumed parent ID extraction logic
        if parent_id in parent_events:
            serialized_sets[parent_id].append(child_record[0])

    # Exclude sets based on criteria
    output_sets = {}
    
    for parent_id, children in serialized_sets.items():
        parent_record = parent_events[parent_id]
        if not children:  # No children, exclude this parent
            continue

        # Check if all children have the same 3 Digit Project Code
        project_codes = {child["3 Digit Project Code"] for child in children}
        if len(project_codes) > 1:  # If not unique, exclude
            continue

        # Update parent project code if children have the same code
        if project_codes:
            parent_record["3 Digit Project Code"] = list(project_codes)[0]

        # Store the parent with its children
        output_sets[parent_record["Acronym"]].append((parent_record, children))

    return output_sets

def print_output(sorted_sets):
    """ Prints the output in the required format. """
    for acronym in sorted(sorted_sets):
        for parent_record, children in sorted_sets[acronym]:
            # Print parent record
            print(f"{parent_record['Event ID']},{parent_record['Event Title']},{parent_record['Acronym']},"
                  f"{parent_record['Project Code']},{parent_record['3 Digit Project Code']},"
                  f"{parent_record['Record Type']}")
            # Print child records
            for child in sorted(children, key=lambda x: (x["Event Title"], x["Event ID"])):
                print(f"{child['Event ID']},{child['Event Title']},{child['Acronym']},"
                      f"{child['Project Code']},{child['3 Digit Project Code']},"
                      f"{child['Record Type']},{parent_record['Event ID']}")  # Append parent ID

def main():
    records = parse_csv(sys.stdin)
    sorted_sets = process_events(records)
    print_output(sorted_sets)

if __name__ == "__main__":
    main()
