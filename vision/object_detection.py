import cv2
from ultralytics import YOLO
import serial
import time

# Load YOLO model
model = YOLO("yolov8n.pt")

# Connect to Arduino
arduino = serial.Serial('COM3', 9600)   # Change COM port if needed
time.sleep(2)

# Start webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    
    # YOLO detection
    results = model(frame)

    for r in results:
        for box in r.boxes:
            class_id = int(box.cls[0])
            confidence = float(box.conf[0])

            if confidence > 0.5:
                label = model.names[class_id]

                # Send signal to Arduino
                if label == "bottle":
                    arduino.write(b'1')

                if label == "cup":
                    arduino.write(b'2')

                # Draw bounding box
                x1,y1,x2,y2 = map(int, box.xyxy[0])
                cv2.rectangle(frame,(x1,y1),(x2,y2),(0,255,0),2)
                cv2.putText(frame,label,(x1,y1-10),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            0.9,(0,255,0),2)

    cv2.imshow("YOLO Detection", frame)

    if cv2.waitKey(1) == 27:
        break

cap.release()
cv2.destroyAllWindows()
