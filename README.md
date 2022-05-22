# Final-Project
Dự án game cuối kì

Commit lần thứ 2:
Các tính năng mới: 
- Bug đã được sửa và tinh chỉnh hiệu năng
- Đã hoàn thiện hệ thống âm thanh
- Cải tiến hệ thống giao diện người dùng

Báo cáo dự án cuối kì cho học phần INT2215 1 - Lập trình nâng cao

Họ và tên: Lê Công Hoàng

MSSV: 21020322
1. Hướng dẫn cài đặt:
- Cách tải game: Tải file Minesweeper Alpha.rar từ repository này về, giải nén rồi nhấp vào game.exe hoặc Minesweeper Alpha để chơi.
2. Mô tả chung về trò chơi, các ý tưởng chính

a) Mô tả chung về trò chơi:

+ Tên trò chơi: Minesweeper
+ Được làm bằng ngôn ngữ lập trình C++, nền tảng đồ họa SDL 2.0
+ Cách chơi: Cho một bảng ô vuông với các ô vuông có mìn và không có mìn, các ô không có mìn sẽ có 1 con số, con số đó biểu thị số lượng mìn xung quanh ô đó. Bạn chỉ thắng khi mở hết tất cả các ô vuông không có mìn, và thua khi mở phải ô có mìn. Nhấn chuột trái để mở ô vuông, nhấn chuột phải để gắn/gỡ cờ. Các ô có cờ không thể mở được.

b) Các ý tưởng chính:
+ Gameplay cơ bản của game dò mìn
+ Hệ thống chọn độ khó
+ Hệ thống giao diện người dùng
+ Hệ thống âm thanh
3. Mô tả các chức năng đã cài đặt, kèm video minh họa (chèn link video youtube)

Link video youtube: https://youtu.be/hC4ocVkv-ps
Các chức năng được cài đặt trong trò chơi:
+ Hệ thống âm thanh hoàn chỉnh: Nhạc nền, hiệu ứng âm thanh khi click chuột, dính mìn,..., hệ thống các nút để điều khiển tiếng (tắt/mở tiếng)
+ Hệ thống giao diện tương tác với người dùng: Menu, các phím bấm, hành động khi bấm phím ESC, hành động chuyển màn hình và thay đổi trạng thái của game (từ Menu đến hướng dẫn...)
+ Hệ thống đồ họa hiển thị được lập trình với SDL 2.0
+ Gameplay cơ bản của game dò mìn
+ Hệ thống chọn độ khó trước khi chơi (Dễ, Trung bình, Khó)
4. Các kỹ thuật lập trình được sử dụng trong chương trình (mảng, con trỏ, cấu trúc, lớp, đồ họa ...)
+ Kĩ thuật lập trình đồ họa bằng SDL 2.0
+ Kĩ thuật lập trình âm thanh bằng SDL 2.0 Mixer
+ Kĩ thuật lập trình hướng đối tượng bằng lớp để refactor code và phân tách rõ ràng các đối tượng của chương trình
+ Kĩ thuật tách file và refactor code
+ Các kiến thức khác được sử dụng: Mảng, con trỏ, hệ thống điều khiển trạng thái game bằng vòng lặp và cấu trúc điều kiện, hệ thống tạo số ngẫu nhiên,...
+ Hệ thống các phím GUI được tự vẽ.
5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình

a) Những kiến thức và kinh nghiệm đã học được sau dự án:
+ Học được cách vận hành của một game, đặc biệt là các game loop
+ Cách sử dụng SDL 2.0 để tạo một chương trình đồ họa có đồ họa và âm thanh
+ Củng cố kiến thức sử dụng ngôn ngữ lập trình C++
+ Cách tổ chức code, cách debug để tăng cường hiệu năng cho phần mềm

b) Hướng phát triển tiếp theo:
+ Do hệ thống tạo level dò mìn là hệ thống được tạo ngay từ trước, nên vẫn có trường hợp thua ngay từ lượt chơi đầu tiên
-> Hướng cải thiện: Tạo một hệ thống tạo bảng ngẫu nhiên tránh ô đầu tiên được chọn
+ Tính năng mới cần thêm:
* Một hệ thống tạo level tự chọn (nhập các số liệu của bảng ô vuông theo ý người dùng, không chỉ giới hạn trong 3 độ khó)
* Hệ thống thời gian chơi, hệ thống pause game
* Hệ thống save/load màn chơi
* Các chế độ chơi mới
* Bảng thành tích Leaderboard
* Chế độ đối kháng qua mạng Internet

c) Kết luận: Game đến nay đã được sửa chữa và tinh chỉnh, nhưng do là sản phẩm tự code thủ công nên vẫn còn rất nhiều thiếu sót có thể được cải tiến thêm về sau. Tuy nhiên, đây cũng là dấu mốc đáng nhớ trong việc bước vào ngành lập trình.
