# VLSI Design of FIR Filter for DSP Applications

## Project Overview

This project implements an **8-tap Finite Impulse Response (FIR) filter** using Verilog HDL for digital signal processing applications.

The FIR filter is designed using a shift-register-based architecture with predefined symmetric filter coefficients. MATLAB is used for coefficient generation and analysis, while **AMD Vivado** is used for RTL design and simulation.

A Verilog testbench is developed to apply input samples and verify the FIR filter output through simulation waveforms.

The project demonstrates the basic VLSI design flow from **FIR coefficient generation to Verilog RTL implementation and functional simulation**.
## Objectives

- To design an 8-tap FIR filter for digital signal processing applications.
- To generate and analyze FIR filter coefficients using MATLAB.
- To implement the FIR filter using Verilog HDL.
- To develop a shift-register-based FIR filter architecture.
- To create a Verilog testbench for functional verification.
- To simulate the FIR filter design using AMD Vivado.
- To observe and analyze the input and output waveforms.
- To study basic VLSI design considerations such as area, speed, and power.
- To understand the FPGA/ASIC-oriented RTL design flow for digital signal processing applications.
## Project Requirements

The project follows the requirements for **VLSI Design of FIR Filter for DSP Applications**.

### Requirements

- Generate FIR filter coefficients using MATLAB.
- Implement the FIR filter using Verilog HDL.
- Develop a suitable Verilog testbench.
- Simulate the design using an FPGA/ASIC design tool.
- Verify the FIR filter functionality using simulation waveforms.
- Study the design in terms of area, speed, and power considerations.
## Tools and Technologies

| Tool / Technology | Purpose |
|---|---|
| MATLAB | FIR coefficient generation and analysis |
| Verilog HDL | FIR filter RTL implementation |
| AMD Vivado | RTL simulation and waveform verification |
| FPGA/ASIC Design Concepts | VLSI-oriented digital hardware design |
## FIR Filter Specifications

| Parameter | Specification |
|---|---|
| Filter Type | Finite Impulse Response (FIR) |
| Number of Taps | 8 |
| Input Width | 16-bit signed |
| Output Width | 32-bit signed |
| HDL | Verilog |
| Coefficient Generation | MATLAB |
| Simulation Tool | AMD Vivado |
| Clock Period | 10 ns |
| Clock Frequency | 100 MHz |
| Architecture | Shift-Register Based |
| Coefficients | 1, 6, 21, 36, 36, 21, 6, 1 |
## FIR Filter Equation

A Finite Impulse Response (FIR) filter produces an output based on the current input sample and a finite number of previous input samples.

The general FIR filter equation is:

y[n] = Σ h[k] × x[n-k]

For the implemented 8-tap FIR filter:

y[n] = h0×x[n] + h1×x[n-1] + h2×x[n-2] + h3×x[n-3]
     + h4×x[n-4] + h5×x[n-5] + h6×x[n-6] + h7×x[n-7]

where:

- x[n] represents the input samples.
- y[n] represents the filtered output.
- h[k] represents the FIR filter coefficients.
- n represents the current sample index.

The coefficients used in this project are:

[1, 6, 21, 36, 36, 21, 6, 1]
## FIR Filter Coefficients

The FIR filter uses the following 8 coefficients:


h0 = 1
h1 = 6
h2 = 21
h3 = 36
h4 = 36
h5 = 21
h6 = 6
h7 = 1

## MATLAB Coefficient Generation

MATLAB is used to define and analyze the FIR filter coefficients used in the Verilog implementation.

The coefficient sequence used in this project is:

[1 6 21 36 36 21 6 1]

## FIR Filter Architecture

The implemented FIR filter uses a **shift-register-based architecture**.

The main functional blocks are:

1. Input sample (`x_in`)
2. 8-stage shift register
3. FIR coefficient multiplication
4. Accumulation of multiplication results
5. Registered output (`y_out`)

### Block Diagram
                    FIR FILTER

                     x_in
                       |
                       v
              +----------------+
              |  Shift Register |
              |   8 Stages      |
              +----------------+
                | | | | | | | |
                v v v v v v v v
               × × × × × × × ×
               | | | | | | | |
              h0 h1 h2 h3 h4 h5 h6 h7
                \ \ \ \ | / / /
                 \ \ \ \|/ / /
                  +-----------+
                  |    Adder  |
                  |    /      |
                  +-----------+
                       |
                       v
                     y_out

## Verilog RTL Implementation

The FIR filter is implemented using Verilog HDL.

The main design file is:


fir_filter.v

## Verilog Testbench

The FIR filter is verified using a dedicated Verilog testbench.

The testbench file is:

fir_filter_tb.v

### Input Sequence

The following input samples are applied to the FIR filter during simulation:

10
20
30
40
50
60
70
80
90
100
0
## Vivado Simulation

The FIR filter RTL design is simulated using **AMD Vivado**.

The simulation verifies the behavior of the FIR filter by applying the testbench input samples and observing the resulting output signal.

The following signals are observed during simulation:

- `clk` – Clock signal
- `rst` – Reset signal
- `x_in` – FIR input sample
- `y_out` – FIR filtered output

The simulation waveform is used to verify the timing and functional behavior of the FIR filter.
## Simulation Results

The simulation confirms that the FIR filter operates correctly.

Initially, the output remains zero while the reset signal is active. After the reset is released, the input samples are shifted through the 8-stage delay line.

As successive input samples enter the filter, each stored sample is multiplied by its corresponding FIR coefficient and the products are accumulated to generate the output.

The output response increases as more input samples contribute to the FIR calculation, demonstrating the expected behavior of the 8-tap FIR filter.
## Simulation Waveform

The FIR filter simulation waveform can be observed in AMD Vivado by monitoring the clock, reset, input, and output signals.

The main signals are:
clk
rst
x_in
y_out

## Design Considerations: Area, Speed and Power

The FIR filter design involves three important VLSI design parameters: area, speed, and power.

### Area

The basic FIR implementation requires:

- Shift registers for storing input samples.
- Multiplication operations for the filter coefficients.
- Addition logic for accumulating the multiplication results.
- Control and reset logic.

The actual FPGA resource utilization depends on the target FPGA device and synthesis results.

### Speed

The testbench uses a 10 ns clock period, corresponding to a nominal clock frequency of 100 MHz.

The maximum operating frequency of the synthesized design depends on the target FPGA, logic depth, routing, and implementation architecture.

### Power

Power consumption depends on clock frequency, switching activity, logic utilization, and the target FPGA technology.

Power can potentially be reduced using techniques such as coefficient optimization, reduced switching activity, resource sharing, and pipelining.

Actual area, timing, and power values can be obtained by performing synthesis, implementation, timing analysis, and power analysis in Vivado.
## Applications

FIR filters are widely used in digital signal processing and VLSI-based systems.

Some common applications include:

- Audio and speech signal processing
- Noise reduction and signal filtering
- Digital communication systems
- Wireless communication
- Biomedical signal processing
- Sensor signal conditioning
- Image and video processing
- Software-defined radio
- Embedded DSP systems
## Future Improvements

The FIR filter can be further improved in the following ways:

- Implement coefficient symmetry to reduce the number of multipliers.
- Increase the number of filter taps for improved filtering performance.
- Implement a pipelined FIR architecture to improve operating speed.
- Compare direct-form and transposed-form FIR architectures.
- Perform FPGA synthesis and analyze LUT, flip-flop, and DSP utilization.
- Perform detailed timing analysis to determine the maximum operating frequency.
- Perform power analysis using Vivado.
- Compare area, speed, and power for different FIR architectures.
- Compare the Verilog output with MATLAB simulation results.
- Implement the design on a physical FPGA development board.
## Conclusion

An 8-tap Finite Impulse Response (FIR) filter was designed using Verilog HDL for digital signal processing applications.

The filter uses the coefficient set:

[1, 6, 21, 36, 36, 21, 6, 1]

## Project Structure

VLSI-Design-of-FIR-Filter/
│
├── README.md
├── fir_filter.v
├── fir_filter_tb.v
├── fir_coefficients.m
└── FIR_Filter_Graphs.png

## Author

**Amruth Kumar Ronanki**

B.Tech – Electrical and Electronics Engineering
