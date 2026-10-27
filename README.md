# HƯỚNG DẪN CÀI VÀ BIÊN DỊCH

Hướng dẫn chi tiết cách thiết lập môi trường, biên dịch mã nguồn và chạy chương trình Clinic Management trên máy tính cá nhân.

## ***1. Yêu cầu hệ thống***

* Để biên dịch và chạy được dự án C/C++ này, máy tính của bạn cần trang bị các công cụ sau:

* Trình biên dịch C/C++ (Compiler): GCC / G++ (Khuyên dùng bộ công cụ MinGW-w64 hoặc w64devkit trên Windows, GCC trên Linux/macOS).

* Trình chỉnh sửa mã nguồn (IDE/Code Editor): Visual Studio Code (hoặc Dev-C++, Code::Blocks).

## ***2. Tải mã nguồn về máy***

* Mở Terminal (hoặc Git Bash / Command Prompt) trên máy tính và chạy lệnh sau để tải dự án từ GitHub:

   ```git clone https://github.com/phamanhtuan270708-creator/ClinicManagement.git```

   ```cd ClinicManagement```


## ***3. Hướng dẫn biên dịch dự án***

* Dự án gồm nhiều file nguồn (.cpp) và file định nghĩa chung (.h). Cần biên dịch gộp toàn bộ các file nguồn cùng một lúc.

### ***Cấu trúc file mã nguồn:***

* clinic.h: File header chứa các cấu trúc dữ liệu (struct), macro định nghĩa và hàm tiện ích dùng chung.

* main.cpp: File chính chứa luồng điều hướng Menu (int main()).

* patientAndQueue.cpp: Module quản lý danh sách bệnh nhân và hàng chờ.

* records.cpp: Module quản lý hồ sơ khám bệnh.

* prescription.cpp: Module quản lý đơn thuốc và thanh toán.

### ***Lệnh biên dịch chuẩn:***

##### Mở Terminal tại thư mục gốc của dự án và chạy lệnh:

```g++ main.cpp patientAndQueue.cpp prescription.cpp records.cpp -o ClinicManagement.exe```

> Lưu ý: Không biên dịch riêng lẻ từng file .cpp (ví dụ: g++ main.cpp)

## ***4. Hướng dẫn chạy chương trình***

##### Sau khi biên dịch thành công, trình biên dịch sẽ tạo ra file thực thi ClinicManagement.exe.

#### *Windows:*

* PowerShell (VS Code):

> .\ClinicManagement.exe

* Command Prompt (CMD):

> ClinicManagement.exe


#### *Linux / macOS:*

> ./ClinicManagement.exe
