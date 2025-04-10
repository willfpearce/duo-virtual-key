package virtual_fido

import (
	"io"

	"github.com/bulwarkid/virtual-fido/ctap"
	"github.com/bulwarkid/virtual-fido/ctap_hid"
	"github.com/bulwarkid/virtual-fido/fido_client"
	"github.com/bulwarkid/virtual-fido/u2f"
	"github.com/bulwarkid/virtual-fido/usbip"
	"github.com/bulwarkid/virtual-fido/util"
)

func Start(client fido_client.FIDOClient) {
	ctapServer := ctap.NewCTAPServer(client)
	u2fServer := u2f.NewU2FServer(client)
	ctapHIDServer := ctap_hid.NewCTAPHIDServer(ctapServer, u2fServer)
	usbDevice := usbip.NewUSBDevice(ctapHIDServer)
	server := usbip.NewUSBIPServer(usbDevice)
	server.Start()
}


func SetLogOutput(out io.Writer) {
	util.SetLogOutput(out)
}
