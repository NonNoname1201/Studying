<?php
class Database {
    private $host = 'localhost';
    private $db_name = 'ogrodyJap';
    private $username = 'base_user';
    private $password = 'password';
    private $conn;

    public function connect() {
        $this->conn = null;

        try {
            $this->conn = new PDO('mysql:host=' . getenv('DB_HOST') . ';dbname=' . getenv('DB_NAME'), 
                                  getenv('DB_USERNAME'), getenv('DB_PASSWORD'));
            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch(PDOException $e) {
            echo 'Connection Error: ' . $e->getMessage();
        }

        return $this->conn;
    }
    
    public function connectAs($currentUsername, $currentPassword) {
        $this->conn = null;

        try {
            $this->conn = new PDO('mysql:host=' . $this->host . ';dbname=' . $this->db_name, 
                                  $this->username, $this->password);
            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $stmt = $this->conn->prepare("SELECT password FROM users WHERE username = ?");
            $stmt->execute([$currentUsername]);
            $user = $stmt->fetch(PDO::FETCH_ASSOC);

            if ($user && password_verify($currentPassword, $user['password'])) {
                return $this->conn;
            } else {
                return 'Invalid username or password';
            }
        } catch(PDOException $e) {
            return 'Connection Error: ' . $e->getMessage();
        }
    }

    public function getUserByUsername($username) {
        $stmt = $this->conn->prepare("SELECT * FROM users WHERE username = ?");
        $stmt->execute([$username]);
        $user = $stmt->fetch(PDO::FETCH_ASSOC);

        return $user;
    }

    public function createUser($username, $hashedPassword, $userType) {
        $stmt = $this->conn->prepare("INSERT INTO users (username, password, user_type) VALUES (?, ?, ?)");
        $stmt->execute([$username, $hashedPassword, $userType]);
    }
}
?>