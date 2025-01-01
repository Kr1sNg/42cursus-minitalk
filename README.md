## [Step-by-Step Guide to Minitalk Project at School 42](https://medium.com/@Kr1sNg/step-by-step-guide-to-minitalk-project-at-school-42-deacf16369ec)


### 📝 **Introduction**

Minitalk is a School 42 project designed to teach inter-process communication (IPC) using UNIX signals (`SIGUSR1` and `SIGUSR2`). The goal is to create a client-server program where the client sends a message, character by character, to the server using binary signals.

In this guide, I'll walk you step-by-step through my implementation of Minitalk, explaining both the **server** and **client** code.

![image](https://github.com/user-attachments/assets/711833c5-0a2e-4969-bb48-f5e61b80fcd4)

---

## 📡 **1. Understanding the Server**

The server is responsible for:

- Receiving signals from the client.
- Reconstructing the binary data into characters.
- Printing the received message.
- Notifying the client when ready to receive the next bit or when the message is fully received.

### **1.1 Server Code**

```c
see in files
```

### **1.2 Explanation**

1. **Signal Handling:**

   - The server uses two signals:
     - `SIGUSR1`: Represents a binary `1`.
     - `SIGUSR2`: Represents a binary `0`.
   - Each signal corresponds to one bit of a character.

2. **Tracking Client PID:**

   - `info->si_pid` contains the PID of the client that sent the signal.
   - The server stores this PID in `pid_client` to send acknowledgment signals back.

3. **Bit Manipulation:**

   - `c |= (0b10000000 >> bit);` sets the current bit to `1` if the signal is `SIGUSR1`.
   - `c &= ~(0b10000000 >> bit);` clears the current bit to `0` if the signal is `SIGUSR2`.
   - `bit` keeps track of the number of bits received for the current character.

4. **Character Assembly:**

   - When 8 bits (`CHAR_BIT`) are received, they are assembled into a character.
   - If the character equals `OVER` (a predefined termination character), the server ends the message and sends `SIGUSR2` to the client.
   - Otherwise, the server writes the character to the standard output.

5. **Acknowledgment:**

   - After processing each bit, the server sends `SIGUSR1` back to the client to signal readiness for the next bit.

6. **Server Loop:**

   - The `while (42)` loop ensures the server keeps listening for incoming signals indefinitely.

---

## 💻 **2. Understanding the Client**

The client is responsible for:

- Converting each character of the message into binary.
- Sending each bit to the server using `SIGUSR1` or `SIGUSR2`.
- Waiting for server acknowledgment before sending the next bit.

### **2.1 Client Code**

```c
see in files
```

### **2.2 Explanation**

1. **Bitwise Transmission:**
   - Each character is converted to binary.
   - Each bit is sent using `kill` with either `SIGUSR1` (1) or `SIGUSR2` (0).

2. **Client-Side Acknowledgment:**
   - We use only one global variable `g_flag` to keep its value between functions and main. `volatile` (keyword) prevents the compiler from making optimizations that could cause stale or incorrect values when the variable is modified in a signal handler. `sig_atomic_t` (data type) guarantees that functions and main can safely share this variable without race conditions.
   - The client waits (`while (g_flag == 0)`) until the server acknowledges each bit. After the server sends back `SIGUSR1` to confirm the received, `g_flag` changes to `1` to allow the system to send the next bit.

3. **End of Transmission:**
   - A special termination character (`OVER`) indicates the end of the message.
   - If `SIGUSR2` is received, the client knows the message was fully received.

4. **Signal Handlers:**
   - `SIGUSR1`: Sets `g_flag` to `1` to proceed.
   - `SIGUSR2`: Confirms full message receipt and exits.

---

## 🧠 **3. Key Takeaways**

  - The server handles binary signal decoding and ensures data integrity.
  - The client ensures that bits are sent reliably and waits for acknowledgment.
  - Signal handling (`SIGUSR1` and `SIGUSR2`) is the backbone of inter-process communication in this project.

---

## 🚀 **4. Testing the Program**

1. **Compile the server and client:**
```
cc -Wall -Wextra -Werror -L./libft -lft -o server server.c
cc -Wall -Wextra -Werror -L./libft -lft -o client client.c
```

2. **Run the server:**
```
./server
```

3. **Run the client with the server’s PID:**
```
./client <PID> "Hello, Minitalk!"
```

4. **Verify that the server prints the message correctly.**
  - Test with Unicode
  - Test with the long text
  - Test to send messages to the server from numerous clients

---

## 🎓 **5. Conclusion**

Minitalk demonstrates how signals can be used for reliable communication between processes. The server decodes signals into binary data and reconstructs them into a meaningful message, while the client carefully manages bitwise transmission and acknowledgment.

Happy coding, and enjoy your Minitalk journey!

---
#### References:
- [42-cursus gitbook](https://42-cursus.gitbook.io/guide/rank-02/minitalk)
- [Minitalk: Goku and King Kai](https://youtu.be/XqhY9WHahJQ?si=piFL-x67Us0xR876)
