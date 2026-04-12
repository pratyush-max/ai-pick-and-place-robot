from ultralytics import YOLO
import cv2
import serial
import time

arduino = serial.Serial('COM5', 9600)
time.sleep(2)

model = YOLO("yolov8n.pt")
cap = cv2.VideoCapture(0)

last_command = ""

while True:
    ret, frame = cap.read()

    if not ret:
        print("Camera error")
        continue

    h, w, _ = frame.shape
    results = model(frame)

    current_command = "S"

    for r in results:
        for box in r.boxes:
            label = model.names[int(box.cls[0])]

            if label == "bottle":
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                cx = (x1 + x2) // 2

                if cx < w // 3:
                    current_command = "L"
                elif cx > 2 * w // 3:
                    current_command = "R"
                else:
                    current_command = "P"

                break

    if current_command != last_command:
        arduino.write(current_command.encode())
        print("Sent:", current_command)
        last_command = current_command

    annotated_frame = results[0].plot()
    cv2.imshow("YOLO Detection", annotated_frame)

    if cv2.waitKey(1) == 27:
        break

cap.release()
arduino.close()
cv2.destroyAllWindows()
