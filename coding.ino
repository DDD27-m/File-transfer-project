# File-transfer-project
# SERVER SIDE

import socket

def start_serve(host='0.0.0.0', port=5001, filename="received_file.txt", buffer_size=4096):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)

    print("SERVER WAITING FOR CONNECTION...")

    conn, addr = server_socket.accept()
    print(f"CONNECTED BY {addr}")

    with open(filename, 'wb') as f:
        while True:
            bytes_read = conn.recv(buffer_size)
            if not bytes_read:
                break
            f.write(bytes_read)

    conn.close()
    server_socket.close()
    print("FILE RECEIVED AND SERVER CLOSED.")

if __name__ == "__main__":
    start_serve()
