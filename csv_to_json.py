import pandas as pd
import json

# Step 1: Read the CSV
# Replace 'yourfile.csv' with the path to your CSV file
df = pd.read_csv('YourProfile.csv')

# Assuming the CSV has columns named: 'Group Number', 'Course User Mapping IDs', 'Assignment Question ID'
# Convert 'Course User Mapping IDs' from string to integers if necessary
df['Course User Mapping IDs'] = df['Course User Mapping IDs'].apply(lambda x: [int(i) for i in x.split()])

# Step 2: Process the data
# Group by 'Group Number' and aggregate the other columns appropriately
grouped = df.groupby('Group Number').agg({
    'Course User Mapping IDs': 'sum',  # Sum lists together
    'Assignment Question ID': 'first'  # Just take the first ID since they should be the same per group
}).reset_index()

# Rename columns to match your output format
grouped.rename(columns={
    'Group Number': 'name',
    'Course User Mapping IDs': 'course_user_mapping_ids',
    'Assignment Question ID': 'assignment_question_id'
}, inplace=True)

# Format the 'name' column to prepend with 'Group '
grouped['name'] = grouped['name'].apply(lambda x: f"Group {x}")

# Step 3: Convert to JSON
# Convert the DataFrame to a dictionary and then dump to JSON
result = grouped.to_dict(orient='records')
json_data = json.dumps(result, indent=4)

# Print or save the JSON data
print(json_data)
