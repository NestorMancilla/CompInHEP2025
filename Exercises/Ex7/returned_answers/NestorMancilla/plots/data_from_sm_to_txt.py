with open("../hdecay/br.sm2", "r") as infile, open("data.txt", "w") as outfile:
    for _ in range(3):  # Skip the first 3 lines (header and separator)
        next(infile)
    
    for line in infile:
        if line.strip():
            columns = line.split()
            mh = float(columns[0])
            width = float(columns[-1])
            outfile.write(f"{mh} {width}\n")
