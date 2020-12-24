#!/bin/sh

influxd --config /etc/influxdb.conf & telegraf --config /etc/telegraf.conf -config-directory /etc/telegraf.conf.d/
