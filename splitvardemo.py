def flatten_table(table, parent_prefix=''):
    """
    Recursively flattens a table with multidimensional columns or nested structures.
    
    Parameters:
    - table: A nested dictionary representing the table to be flattened.
    - parent_prefix: A string used to prefix column names to indicate nesting (used in recursion).
    
    Returns:
    - A flat dictionary with all columns flattened.
    """
    flat_table = {}
    
    for column_name, value in table.items():
        # Construct new column name based on parent_prefix
        new_column_name = f"{parent_prefix}_{column_name}" if parent_prefix else column_name
        
        # If value is a dictionary, it's a nested structure; recurse
        if isinstance(value, dict):
            flat_table.update(flatten_table(value, new_column_name))
        # If value is a list (or any iterable other than string), handle as multidimensional column
        elif isinstance(value, (list, tuple)) and not isinstance(value, str):
            for i, item in enumerate(value):
                # For each item in the list, append an index to the column name and flatten further if needed
                indexed_column_name = f"{new_column_name}_{i}"
                if isinstance(item, dict):
                    flat_table.update(flatten_table(item, indexed_column_name))
                else:
                    flat_table[indexed_column_name] = item
        else:
            # Base case: just a regular column
            flat_table[new_column_name] = value
    
    return flat_table

# Example usage:
if __name__ == "__main__":
    # Example table with both multidimensional and nested structures
    example_table = {
        "column1": "value1",
        "multidimensional_column": ["item1", "item2"],
        "nested_table": {
            "child1": "value2",
            "child2": ["nested_item1", "nested_item2"],
            "deeply_nested": {
                "deep_child": "deep_value"
            }
        }
    }
    
    flat_table = flatten_table(example_table)
    print(flat_table)