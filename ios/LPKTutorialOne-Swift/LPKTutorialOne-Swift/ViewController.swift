//
//  ViewController.swift
//  LPKTutorialOne-Swift
//
//  Created by CARSON LI on 2016-06-30.
//  Copyright © 2016 Liquid Analytics. All rights reserved.
//

import UIKit
import LiquidPlatformKit

class ViewController: UIViewController, LSCSeasideApplicationDelegate {
    
    @IBOutlet weak var passwordField: UITextField!
    @IBOutlet weak var progressBar: UIProgressView!
    @IBOutlet weak var usernameField: UITextField!
    @IBOutlet weak var loginButton: UIButton!
    @IBOutlet weak var infoLabel: UILabel!
    @IBOutlet weak var dummyButton: UIButton!
    var loginCallback: ((String, String) -> Void)?
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        
        self.dummyButton.hidden = true
        self.infoLabel.text = ""
        self.progressBar.progress = 0.0
        self.progressBar.hidden = true
        
        //load the DB in the background, typically there is a loading screen that goes here
        //so we don't block the main thread
        
        LDMDataManager.sharedInstance().executeAsynch {
            LDMDataManager.sharedInstance().openDatabaseWithName("MovieCollection")
            LSCSyncController.sharedInstance().startWithDelegate(self);
            
            if let deviceId = NSUserDefaults.standardUserDefaults().objectForKey("seasideCustomDeviceId")
            {
                print(deviceId)
            }
            
            self.loginButton.enabled = true
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func loginButtonPressed()
    {
        self.loginButton.enabled = false
        self.usernameField.enabled = false
        self.passwordField.enabled = false
        self.progressBar.hidden = false
        LDMDataManager.sharedInstance().executeAsynch {
            if let username = self.usernameField.text
            {
                if let password = self.passwordField.text
                {
                    self.loginCallback!(username, password)
                }
            }
            
        }
    }

    func updateLoginStatusLabel(status: String?, enable: Bool) {
        dispatch_async(dispatch_get_main_queue()) {
            self.infoLabel.text = status;
        }
    }
    
    func authenticateWithMessage(message: String?, userEditable: Bool, providePasscode: Bool, callback: ((String, String) -> Void)?) {
        self.loginCallback = callback;
        dispatch_async(dispatch_get_main_queue()) {
            self.loginButton.enabled = true
            self.usernameField.enabled = true
            self.passwordField.enabled = true
            self.passwordField.text = "";
            self.infoLabel.text = message;
        }
       
    }
    
    func registeringWithMessage(message: String?, syncingData: Bool, syncProgress: Float) {
        dispatch_async(dispatch_get_main_queue()) {
            self.infoLabel.text = message;
            self.progressBar.progress = syncProgress;
        }
    }
    
    func selectCommunity() {
        LSCSyncController.sharedInstance().communitySelected("MovieCollection");
    }
    
    func  registered() {
        dispatch_async(dispatch_get_main_queue()) {
            self.performSegueWithIdentifier("showMovieSegue", sender: nil)
        }
    }

}
