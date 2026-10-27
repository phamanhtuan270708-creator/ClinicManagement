 ## QUẢN LÝ PHÒNG KHÁM TƯ NHÂN

## 1. Giới thiệu

Dự án **Quản lý phòng khám tư nhân** thiết kế dữ liệu cho các nghiệp vụ tiếp nhận bệnh nhân, lịch hẹn, lượt khám, hồ sơ khám, đơn thuốc và thanh toán. Mô hình tách thông tin cá nhân của bệnh nhân khỏi dữ liệu phát sinh theo từng lượt khám, đồng thời hỗ trợ cả luồng bệnh nhân đặt lịch online và tiếp nhận trực tiếp.

Các phần nghiệp vụ thể hiện trong thiết kế dữ liệu:

- Quản lý thông tin bệnh nhân và lịch hẹn online
- Theo dõi hàng đợi chờ khám
- Ghi nhận lượt khám, triệu chứng, chiều cao, cân nặng và chẩn đoán
- Lập đơn thuốc gồm các chi tiết thuốc và cách dùng
- Ghi nhận thanh toán theo chi phí thực tế của lượt khám
- Liên kết lượt khám trước để lưu thông tin tái khám

Quy chuẩn đặt tên mã nguồn: **camelCase**.

## 2. Thành viên và phân công

| STT | Họ tên | Nhiệm vụ |
|:---:|--------|----------|
| 1 | PHẠM ANH TUẤN | - Thiết kế `Patient` (bệnh nhân)<br>- Thiết kế `Appointment` (lịch hẹn online)<br>- Thiết kế `Queue` (số thứ tự chờ)<br>- Thiết kế `Visit` (lượt khám) |
| 2 | LÊ NGUYỄN MINH ĐỨC | - Thiết kế `MedicalRecord` (hồ sơ khám)<br>- Thiết kế `PrescriptionItem` (chi tiết thuốc)<br>- Thiết kế `Prescription` (đơn thuốc)<br>- Thiết kế `Payment` (thanh toán) |

## 3. Thiết kế cấu trúc dữ liệu

| Cấu trúc (Struct) | Thuộc tính  | Mô tả & ghi chú |
|-------------------|------------------|-----------------|
| `Patient` | `patient_id`, `full_name`, `phone`, `date_of_birth` | Thông tin bệnh nhân, dùng chung cho cả luồng online và offline. |
| `Queue` | `arrival_sime`, `type`, `current_status` | Số thứ tự khám và thứ tự ưu tiên; phục vụ tiếp nhận trực tiếp hoặc khách online đã đến phòng khám. |
| `Visit` | `visit_id`, `patient_id`, `case_id`, `visit_date` | Lượt khám thực tế. `case_id` sinh mã đợt khám phân biệt tái khám và bệnh lý mới qua mỗi lượt khám. |
| `MedicalRecord` | `visit_id`, `symptoms`, `height`, `weight`, `diagnosis` | Hồ sơ theo từng lượt khám; lưu dữ liệu phát sinh mà không ghi đè thông tin cá nhân. |
| `PrescriptionItem` | `medicine_id`, `quantity`, `unitprice`, `usage` | Chi tiết thuốc gồm mã thuốc, số lượng, đơn giá và cách dùng. |
| `Prescription` | `prescription_id`, `visit_id`, `items` | Đơn thuốc hoàn chỉnh gắn với một lượt khám cụ thể. |
| `Payment` | `payment_id`, `visit_id`, `total_amount`, `payment_methods` | Thanh toán; chỉ tính phí dịch vụ thực tế phát sinh từ lượt khám. |
| `Appointment` | `appointment_id`, `patient_id`, `appointment_date`, `time_slot`, `status` | Lịch hẹn đặt trước online của bệnh nhân. |

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


