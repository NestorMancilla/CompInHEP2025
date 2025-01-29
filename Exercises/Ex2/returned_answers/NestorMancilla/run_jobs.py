import subprocess

N = 10  
processes = []

for i in range(1, N + 1):
    process = subprocess.Popen(["./HW", str(i)])
    processes.append(process)

for process in processes:
    process.wait()

