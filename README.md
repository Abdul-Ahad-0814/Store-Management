# 🛒 Store Management System

A powerful Store Management System built using **C++**, **Qt**, and **OpenCV**, designed to handle inventory, billing, barcode scanning, and face recognition for secure login.

---

## 🚀 Features

- 🔐 **Face Recognition Login** for admin (OpenCV + Dlib)
- 🛍️ Add, update, delete, and view products
- 📦 Low stock alerts and discount offers
- 🧾 Bill generation with itemized view
- 📸 Barcode scanning via webcam
- 👥 Multiple cashier login system
- 📊 Admin dashboard with reports

---

## 📥 How to Download and Run

### 📁 Clone the Repository
```bash
git clone https://github.com/Abdul-Ahad-0814/Store-Management.git
cd Store-Management
```

### 💻 Run the Application (Without Building)

If you're not compiling the project and just want to run the ready-to-use `.exe`:

1. Go to the following folder:
   ```
   Store-Management/build/Desktop_Qt_6_8_2_MinGW_64_bit-Release/release/
   ```
2. Run:
   ```
   store-management-system.exe
   ```
3. On first-time use:
   - Register an admin account
   - Then log in as admin to access full features

> ⚠️ Ensure your system has Qt & OpenCV runtime DLLs available (either installed or in the same folder as the `.exe`)

---

## 🧱 Build from Source (Optional)

### ✅ Requirements

- Qt Creator (with MinGW or MSVC)
- OpenCV (installed and configured)
- Dlib (optional, for face recognition)

### 🛠️ Build Instructions

1. Open the `.pro` file in **Qt Creator**
2. Select the appropriate kit and build configuration
3. Click **Build** > **Run**

---

## 📁 Folder Structure

```
Store-Management/
├── barcodes/         # Stores scanned barcodes
├── build/            # Build files (can be ignored)
├── opencv/           # Camera & face recognition logic
├── src/              # Main C++ source code
├── ui/               # Qt Designer UI files
├── resources/        # Icons and images
├── README.md
├── main.cpp
└── *.pro or CMakeLists.txt
```

---

## 🙋‍♂️ Author

**Abdul Ahad**  
FAST NUCES, Karachi  
GitHub: [@Abdul-Ahad-0814](https://github.com/Abdul-Ahad-0814)

---

## 📜 License

This project is intended for academic and learning purposes. You're free to use or modify it.
