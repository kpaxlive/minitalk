# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later. You will mainly learn how to use signal functions.

#### Skills
- Rigor
- Unix
- Algorithms & AI

## 🛠️ Usage

**Follow the steps below**

### Instructions

**1. Clone the repository from github**

```bash
git clone https://github.com/kpaxlive/minitalk && cd minitalk/
```
Compile the library by Makefile
To compile the library, go to its path and run:

```bash
 make
```

**3. Open new terminal on the same directory and run the server:**
```bash
./server
```

**4. Open new terminal on the same directory again and run the client with pid of server: **
NOT: first you must get pid (proccess id) from the server.

```bash
./client pid "Your message"
```

**Example of usage**
<img src="./images/usage.png" />
