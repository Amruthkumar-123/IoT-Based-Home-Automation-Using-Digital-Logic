`timescale 1ns / 1ps

//////////////////////////////////////////////////////////////////////////////////
// Project: VLSI Design of FIR Filter for DSP Applications
//
// Module: fir_filter_tb
//
// Description:
// Testbench for the 8-tap FIR filter.
// Input samples are applied sequentially and the filtered
// output is monitored.
//////////////////////////////////////////////////////////////////////////////////

module fir_filter_tb;

    // =========================================================
    // Testbench Signals
    // =========================================================

    reg clk;
    reg rst;
    reg signed [15:0] x_in;

    wire signed [31:0] y_out;

    // =========================================================
    // Device Under Test
    // =========================================================

    fir_filter DUT (
        .clk(clk),
        .rst(rst),
        .x_in(x_in),
        .y_out(y_out)
    );

    // =========================================================
    // Clock Generation
    // 10 ns clock period
    // Frequency = 100 MHz
    // =========================================================

    always #5 clk = ~clk;

    // =========================================================
    // Input Stimulus
    // =========================================================

    initial
    begin

        // Initial conditions
        clk  = 1'b0;
        rst  = 1'b1;
        x_in = 16'sd0;

        // -----------------------------------------------------
        // Apply reset
        // -----------------------------------------------------

        #20;
        rst = 1'b0;

        // -----------------------------------------------------
        // Apply input samples
        // -----------------------------------------------------

        #10 x_in = 16'sd10;
        #10 x_in = 16'sd20;
        #10 x_in = 16'sd30;
        #10 x_in = 16'sd40;
        #10 x_in = 16'sd50;
        #10 x_in = 16'sd60;
        #10 x_in = 16'sd70;
        #10 x_in = 16'sd80;
        #10 x_in = 16'sd90;
        #10 x_in = 16'sd100;

        // -----------------------------------------------------
        // Stop input samples
        // -----------------------------------------------------

        #10 x_in = 16'sd0;

        // Allow FIR filter response to continue
        #200;

        // End simulation
        $finish;

    end

    // =========================================================
    // Monitor Input and Output
    // =========================================================

    initial
    begin

        $display("==================================================");
        $display("       8-TAP FIR FILTER SIMULATION");
        $display("==================================================");
        $display("Time\tInput\tOutput");
        $display("--------------------------------------------------");

        $monitor(
            "%0t\t%d\t%d",
            $time,
            x_in,
            y_out
        );

    end

endmodule
