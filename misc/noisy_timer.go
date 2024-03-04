package main

import (
	"fmt"
	"time"
)

// Main function for the action
func Main(obj map[string]interface{}) map[string]interface{} {
	start := time.Now()

	// Create a large array
	data := make([]int, 100000000)

	// Access elements in a pattern that maximizes cache utilization
	for i := 0; i < len(data); i++ {
		data[i] = i
	}

	for i := 0; i < len(data); i++ {
		// This is a dummy operation
		_ = data[i] * i
	}

	// Calculate the runtime
	runtime := time.Since(start)

	// Create the message
	msg := make(map[string]interface{})
	msg["time"] = fmt.Sprintf("%s", runtime)

	return msg
}

