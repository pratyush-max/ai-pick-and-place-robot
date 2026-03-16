import cv2
import serial
import time
from ultralytics import YOLO

# Load YOLO model
model = YOLO("yolov8n.pt")

# Connect to Arduino
arduino = serial.Serial('COM3', 9600)
time.sleep(2)

# Start webcam
cap = cv2.VideoCapture(0)

while True:

    ret, frame = cap.read()
    if not ret:
        break

    # Run YOLO detection
    results = model(frame)

    detected = False

    for r in results:
        boxes = r.boxes

        for box in boxes:

            cls = int(box.cls[0])
            conf = float(box.conf[0])

            if conf > 0.5:
                detected = True

                x1, y1, x2, y2 = map(int, box.xyxy[0])

                cv2.rectangle(frame, (x1,y1),(x2,y2),(0,255,0),2)
                cv2.putText(frame, "Object",(x1,y1-10),
                cv2.FONT_HERSHEY_SIMPLEX,0.6,(0,255,0),2)

    # Send command to Arduino
    if detected:
        arduino.write(b'A')
        time.sleep(2)
        arduino.write(b'B')
        time.sleep(2)
        arduino.write(b'C')
        time.sleep(2)
        arduino.write(b'D')
        time.sleep(2)

    cv2.imshow("YOLO Detection", frame)

    if cv2.waitKey(1) == 27:
        break

cap.release()
cv2.destroyAllWindows()# Placeholder file for module

