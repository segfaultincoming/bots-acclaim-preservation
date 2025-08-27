import socket
import threading
import sys

def run_echo_server(port):
    """Run an echo server on the specified port"""
    HOST = '0.0.0.0'  # Listen on all available interfaces
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((HOST, port))
        s.listen()
        print(f"Echo server running on {HOST}:{port}")
        
        while True:
            try:
                conn, addr = s.accept()
                with conn:
                    print(f"[Port {port}] Connected by {addr}")
                    while True:
                        data = conn.recv(1024)
                        if not data:
                            break
                        print(f"[Port {port}] Received: {data} from {addr}")
                        conn.sendall(data)
                    print(f"[Port {port}] Client {addr} disconnected")
            except KeyboardInterrupt:
                print(f"\n[Port {port}] Server shutting down...")
                break
            except Exception as e:
                print(f"[Port {port}] Error: {e}")

def main():
    ports = [11000, 11002, 11010]
    
    print("Starting echo servers on ports 11000 and 11002...")
    print("Press Ctrl+C to stop all servers")
    
    threads = []
    
    # Start each server in its own thread
    for port in ports:
        thread = threading.Thread(target=run_echo_server, args=(port,), daemon=True)
        thread.start()
        threads.append(thread)
    
    try:
        # Keep main thread alive
        for thread in threads:
            thread.join()
    except KeyboardInterrupt:
        print("\nShutting down all echo servers...")
        sys.exit(0)

if __name__ == "__main__":
    main()
