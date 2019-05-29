#include <stdio.h>

#include <GameEngine.h>

#include "NavigationModule.h" 

#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>
#import <Cocoa/Cocoa.h>
#include "test.h"

int main(int argc, const char * argv[])
{
//    TestAppDelegate* appDel = [TestAppDelegate alloc];
//    [NSApp setDelegate:appDel];
//
//    NSApplication* app = [NSApplication sharedApplication];
//    
//    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
//    [NSApp activateIgnoringOtherApps:YES];
//
//    app.delegate = appDel;
//    [app run];
//
//    return NSApplicationMain(argc, argv);
    
    GameEngine eng;
    eng.Initialize();

    //eng.CreateModule<NavigationModule>();

    eng.Play();

    return 0;
}
