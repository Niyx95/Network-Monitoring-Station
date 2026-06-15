#Script to run influxDB and MQTT

import paho.mqtt.client as mqtt
from datetime import datetime
from influxdb_client import InfluxDBClient, Point
from influxdb_client.client.write_api import SYNCHRONOUS

#InfluxDB conf
INFLUX_URL = "http://localhost:8086"
INFLUX_TOKEN = "token here"
INFLUX_ORG = "nyx2k.org"
INFLUX_BUCKET = "network"

#MQTT conf
MQTT_BROKER = "localhost"
MQTT_TOPIC = "network"

#InfluxDB client
influx_client = InfluxDBClient(url=INFLUX_URL, token=INFLUX_TOKEN, org=INFLUX_ORG)
write_api = influx_client.write_api(write_options=SYNCHRONOUS)

#function to get and write msg
def on_message(client, userdate, message):
    payload = message.payload.decode("UTF-8")
    status = 1 if "up" in payload else 0
    print(f"Recived {payload} >>  writing {status} to InfluxDB")

    point = Point("network status") \
        .tag("host", "router") \
        .field("status", status) \
        .time(datetime.utcnow())
    
    write_api.write(bucket= INFLUX_BUCKET, record=point)

#function to connect to MQTT
def on_connect(client, userdate, flags, rc):
    print("connecting to MQTT Broker")
    client.subscribe(MQTT_TOPIC)

#create Obj. and pass in functions
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

#connect and loop 4ever
client.connect(MQTT_BROKER, 1883)
print("Starrting MQTT listener..")
client.loop_forever()