const std = @import("std");
const print = std.debug.print;

const c = @cImport({
    @cInclude("math.h");
});

pub fn main() !void {
    const angle = 893.7;
    const circle = 360;

    const result = c.fmod(angle, circle);

    print("The normalized angle of {d: >3.1} degrees is {d: >3.1} degrees.\n", .{ angle, result });
}
